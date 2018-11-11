/* vigenere cipher tool*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* converts all the characters in str to uppercase */
void upper(char* str) {
  for(unsigned int i = 0; i < strlen(str); i++) {
    if(str[i] >= 97 && str[i] <= 122) {
      str[i] = str[i] - 32;
    }
  }
}

/* encrypts msg with key */
char* encrypt(char* msg, char* key) {
  int keylen = strlen(key);
  char* ret = malloc(sizeof(char) * strlen(msg));
  upper(msg);
  upper(key);

  /* ASCII Value of 'A':65 */
  for(unsigned int i = 0; i < strlen(msg); i++) {
    ret[i] = (((msg[i] - 65) + (key[i % keylen] - 65)) % 26) + 65;
  }
  
  return ret;
}

/* decrypts msg with key */
char* decrypt(char* msg, char* key) {
  int keylen = strlen(key);
  char* ret = malloc(sizeof(char) * strlen(msg));
  upper(msg);
  upper(key);

  /* for every character, this essentially solves for x
     in the equation to reverse the encryption algorithm */
  for(unsigned int i = 0; i < strlen(msg); i++) {
    ret[i] = ((((msg[i] - 65) + 26) - (key[i % keylen] - 65)) % 26) + 65;
  }
  
  return ret;
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("usage: %s message keyword\n", argv[0]);
    return -1;
  }

  char* encstr = encrypt(argv[1], argv[2]);
  char* decstr = decrypt(argv[1], argv[2]);
  printf("Encrypted String:\n%s\n", encstr);
  printf("Decrypted String:\n%s\n", decstr);

  free(encstr);
  free(decstr);
  
  return 0;
}
