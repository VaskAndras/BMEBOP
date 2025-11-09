#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define DESC_LEN 60

typedef struct {
    int id;
    char description[DESC_LEN + 1];
    int done; // 0 = not done, 1 = done
} Todo;

void show_done_tasks(Todo tasks[], int n) {
    printf("\n--- Done Tasks ---\n");
    for (int i = 0; i < n; i++) {
        if (tasks[i].done) {
            printf("ID: %d | %s | Status: %s\n",
                   tasks[i].id,
                   tasks[i].description,
                   tasks[i].done ? "Done" : "Not done");
        }
    }
}

void mark_done(Todo tasks[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (tasks[i].id == id) {
            tasks[i].done = 1;
            printf("Task ID %d marked as done.\n", id);
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);
}

int main() {
    Todo tasks[MAX_TASKS];
    
    printf("Enter %d tasks (ID, description):\n", MAX_TASKS);
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].done = 0; // initialize as not done
        printf("Task %d ID: ", i + 1);
        scanf("%d", &tasks[i].id);
        getchar(); // consume newline
        printf("Task %d description: ", i + 1);
        fgets(tasks[i].description, DESC_LEN, stdin);
        // remove newline character if present
        tasks[i].description[strcspn(tasks[i].description, "\n")] = 0;
    }

    int choice;
    printf("\nMenu:\n1. Show done tasks\n2. Mark task as done\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        show_done_tasks(tasks, MAX_TASKS);
    } else if (choice == 2) {
        int id;
        printf("Enter ID of task to mark as done: ");
        scanf("%d", &id);
        mark_done(tasks, MAX_TASKS, id);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}