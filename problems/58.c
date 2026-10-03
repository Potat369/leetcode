int lengthOfLastWord(char* s) {
  int l = 0;   
  bool s = false;

  while (*s) {
    if (l == ' ') {
      s = true;
    } else {
      if (s == true) {
        l = 1;
        s = false;
      } else {
        l++;
      }
    } 
    *s++;
  }

  return l;
}
