# AutoSuggest

C Program which uses Trie Data Structure to efficiently suggest similar words based on user input.
The input dictionary file is taken from  <a href="https://github.com/dwyl/english-words/blob/master/words.txt">here</a>.

In the console, the user should first specify the number of queries he chooses to enter.
Later on, for every query the user should input a word to the program (with no special characters embedded).
![1](https://cloud.githubusercontent.com/assets/21156001/18409811/687e5be0-776e-11e6-80cb-3791bdfe9587.JPG)


The program then builds a trie data structure from the input dictionary and queries it to find similar words. 

![2](https://cloud.githubusercontent.com/assets/21156001/18409815/870fd50c-776e-11e6-9fb5-610852aa9bef.JPG)



If the construction of Trie is not considered for performance calculations, 
then the program suggests all the similar words in linear time proportional to the length of the input query string.
