#include <stdio.h>
#include <string.h>

const char *availableItems[] = {
    "hydraulic pump", "HYDRAULIC PUMP", "PLC module", "plc module",
    "PLC MODULE",     "servo motor",    "SERVO MOTOR"};

int main(void) {

  char item[100];

  printf("Hey. Welcome to the spare parts inventory!\nWhich part do you need? "
         "Write here: ");
  int found = 0;

  while (!found) {
    if (fgets(item, sizeof(item), stdin)) {
      item[strcspn(item, "\n")] = '\0';

      for (int i = 0; i < (sizeof(availableItems) / sizeof(availableItems[0]));
           i++) {
        if (strcmp(item, availableItems[i]) == 0) {
          printf("I have got %s here for you :). Bye!", availableItems[i]);
          found = 1;
          break;
        }
      }

      if (!found) {
        printf("Sorry, couldn't find %s!\n", item);
        printf("Try again: ");
      }
    }
  }
}