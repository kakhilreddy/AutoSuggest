#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#define	ALPHABET_SIZE	26

using namespace std;
struct TNode
{
	bool isEOW;
	TNode *next[ALPHABET_SIZE];
};

TNode *createTrieNode()
{

    TNode *newNode = (TNode*)malloc(sizeof(TNode));
    newNode->isEOW = false;
    int i;
    for(i=0;i<26;i++)
        newNode->next[i] = NULL;
    return newNode;
}
bool insertWordInTrie(TNode *root, char *word)
{
  int len=strlen(word);
  for(int i=0;i<len;i++)
  {
  if(root->next[word[i]-'a']==NULL)
    root->next[word[i]-'a']=createTrieNode();
    root=root->next[word[i]-'a'];



  }
  if(root->isEOW)
    return false;
  root->isEOW=true;
  return true;


}
char str[10000];
int index=0;
void printWordsInTrie(TNode* root){

  if(root==NULL)
    return;
  if(root->isEOW)
  { str[index]='\0';
    cout<<str<<endl;}
  for(int i=0;i<26;i++)
  {

   if(root->next[i]!=NULL)
   {
   str[index]=i+'a';
     index++;
     printWordsInTrie(root->next[i]);
     index--;
     str[index]='\0';



   }
  }

}
int countPrefix=0;
void printWordsInTrie(TNode* root,char* str1){

  if(root==NULL)
    return;
  if(root->isEOW)
  { str[index]='\0';
    cout<<str1<<str<<endl;
    countPrefix++;}
  for(int i=0;i<26;i++)
  {

   if(root->next[i]!=NULL)
   {
   str[index]=i+'a';
     index++;
     printWordsInTrie(root->next[i],str1);
     index--;
     str[index]='\0';




   }
  }

}
bool isLeaf(TNode *root){
    int i;
    for(i = 0;i < ALPHABET_SIZE; i++)
        if(root->next[i] != NULL)
            return false;
    return true;
}


bool deleteWordFromTrie(TNode *root, char *word)
{
 if(root==NULL)
        return false;
  if(word[0]=='\0')
    {
        if(root->isEOW==false)
            return false;

        if(isLeaf(root))
        {
            free(root);
            return true;
        }
        else
        {
            root->isEOW = false;
            return false;
        }

    }
  int idx = word[0] - 'a';
    if(deleteWordFromTrie(root->next[idx], word+1))
    {
        root->next[idx] = NULL;
        if(isLeaf(root) && root->isEOW==false)
        {
            free(root);
            return true;
        }
    }

    return false;



}
TNode* initializeTrie(TNode *root)
{
     fstream fs("words.txt");
    while(!fs.eof())
    {

        char temp[100];
        fs>>temp;
        //cout<<temp<<endl;
        insertWordInTrie(root,temp);

    }

    return root;

}

void printAllPrefix(TNode* root,char *str)
{
    if(root==NULL)
        return;
    for(int i=0;i<strlen(str);i++)
    {

        if(root->next[str[i]-'a']!=NULL)
        {

            root=root->next[str[i]-'a'];

        }
    }


    printWordsInTrie(root,str);


}

int main()
{
    TNode* root=createTrieNode();
initializeTrie(root);
int q;
cout<<"enter no of queries: \n";
cin>>q;
for(int i=0;i<q;i++)
{ char temp[100];
    cout<<"Enter word: ";
    cin>>temp;
    countPrefix=0;
    printAllPrefix(root,temp);
    cout<<"Total No of Suggestions are : "<<countPrefix<<endl;

}

    return 0;
}
