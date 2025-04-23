#include <iostream>
#include <pthread.h>

using namespace std;

const int ARRAY_SIZE = 6;
int arr[ARRAY_SIZE] = {3, 8, 12, 5, 15, 7}; // Example array
int max_value = 0; 
pthread_mutex_t lock; // Mutex for thread safety

void* find_max(void* arg) {
    int* num = (int*)arg;
    pthread_mutex_lock(&lock);
    if (*num > max_value) {
        max_value = *num;
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[ARRAY_SIZE];
    pthread_mutex_init(&lock, NULL);

    // Create a thread for each array element
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, find_max, (void*)&arr[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    cout << "Maximum value in the array: " << max_value << endl;
    pthread_mutex_destroy(&lock);
    return 0;
}
