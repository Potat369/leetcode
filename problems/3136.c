#include <stdbool.h>
#include <stdio.h>

bool isValid(char *word) {
  int count = 0;
  bool hasConsonant = false;
  bool hasVowel = false;

  char curr = word[count];
  while ((curr = word[count]) != '\0') {
    count++;
    if (curr == 'a' || curr == 'o' || curr == 'e' || curr == 'u' ||
        curr == 'i' || curr == 'o' || curr == 'A' || curr == 'O' ||
        curr == 'E' || curr == 'U' || curr == 'I') {
      hasVowel = true;
    } else if (('A' <= curr && curr <= 'Z') || ('a' <= curr && curr <= 'z')) {
      hasConsonant = true;
    } else if (!('0' <= curr && curr <= '9')) {
      return false;
    }
  }

  return count >= 3 && hasVowel && hasConsonant;
}

int main(void) {
  printf("%d\n", isValid("eee333"));

  return 0;
}
