
#include <stdio.h>
#include <string.h>


#define Size 5


typedef struct {
    char buffer[Size];
    int head;          
    int tail;        
    int count;      
} CircularBuffer; 

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}


int isFull(CircularBuffer *cb) {
    return cb->count == Size;
}


int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}


void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
       
        printf("\nBuffer Overflow! cannot add: %c", data);
        return;
    }
    cb->buffer[cb->tail] = data; 
    cb->tail = (cb->tail + 1) % Size;
    cb->count++; 
} 

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
       
        printf("\nBuffer Underflow!\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % Size; 
    cb->count--; 
    return data;
} 

int main() {
    CircularBuffer cb;
    init(&cb); 

    char name[50]; 

    printf("Enter your name: ");
    
    if (scanf("%49s", name) != 1) return 1; 

   
    strcat(name, "CE-ESY"); 

    printf("\nWriting characters to Circular Buffer...\n");
    
    for (int i = 0; i < (int)strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    } 

          printf("\n\nReading characters from Circular Buffer:\n");
         
    while (!isEmpty(&cb)) {
        char c = readBuffer(&cb);
           printf("%c", c);
    }
    
      
    return 0;
}
