/*Consider strings of “A”’s and “B”’s of length n that are built according to the following two
rules:
• for each A already produced, produce an AB
• for each B already produced, produce a BBA.
For example, a string of length n = 13 that initially starts with A in 4 iterations will result in
the following string: ABBBABBABBAAB.
 This program takes an input a string of A’s and B’s and transforms it, it will give a message
  at the point when the string does not follow the rules. However, it will still print the transformed
  string, although it might not follow the rules at later stages.
 */
#include <iostream>
#include <string>
using namespace std;

void check(string str, string & result) {
   /*checks if the string follows the rules - recursively checks the first
   "bba" or "ab", then creates a substring without them, checks until finds
   a mistake or when the length of the substring is 0, takes 2 strings,
   the one which needs to be checked and one which will store the result*/
   if (str.length() == 0) {
      result = "true";
   } else if (str.find("BBA") == 0) {
      check(str.substr(3), result);
   } else if (str.find("AB") == 0) {
      check(str.substr(2), result);
   } else {
      result = "false";
   }
}

string transform(string str) {
   /*transforms "bba" to "b" and "ab" to "a", first finds the positions of the
   combination, checks to see which one comes first, then changes the values and
   increments the position from which it needs to look for the next combination,
   stops when both positions are equal to -1 ,
   takes a string and returns the transformed one*/
   int i = 0;
   int apos = 1;
   int bpos = 1;

   while (true) {
      if (apos == -1 && bpos == -1) {
         break;
      }
      //finds the the combinations starting from the given position
      apos = str.find("AB", i);
      bpos = str.find("BBA", i);

      if ((apos < bpos || bpos == -1) && apos != -1) {
         str.replace(apos, 2, "A");
         i++;
      }
      if ((bpos < apos || apos == -1) && bpos != -1) {
         str.replace(bpos, 3, "B");
         i++;
      }
   }
   return str;
}

string reverse(string & str) {
   /*the main recursive function, first checks to see if the string is valid,
   then transforms it until its length equals 1 */
   string validity;
   check(str, validity);

   if (str.length() == 1) {
      return str;
   } else if (validity == "false") {
      cout << "Your string does not follow the rules.";
   } else {
      str = transform(str);
      cout << str + "\n";
      reverse(str);
   }
   return str;
}

int main() {
   string example = "ABBBABBABBAAB";
   string example2 = "BAOBAB";
   cout << example + "\n";
   reverse(example);
   cout << example2 + "\n";
   reverse(example2);
}
