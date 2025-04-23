#include <iostream>
#include <pthread.h>

using namespace std;

const int ARRAY_SIZE = 6;
int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6}; 
int sum = 0;
pthread_mutex_t lock;

void* sum_array(void* arg) {
    int* num = (int*)arg;
    pthread_mutex_lock(&lock);
    sum += *num;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {  // Ensure main() is present
    pthread_t threads[ARRAY_SIZE];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, sum_array, (void*)&arr[i]);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    cout << "Sum of the array: " << sum << endl;

    pthread_mutex_destroy(&lock);
    return 0;
}
