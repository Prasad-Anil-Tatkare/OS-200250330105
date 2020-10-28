#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define serial_con struct serial_config

serial_con{
    int baud_rate, stop_bit;
    char parity;
};


void *serial_thread(void *arg){
    //struct serial_config *s;
    //s = arg;
    printf("\nSerial Configuration is:\nBaud Rate: %d\nStop Bit: %d\nParity: %c\n",((serial_con *)arg)->baud_rate,((serial_con *)arg)->stop_bit,((serial_con *)arg)->parity);
}

int main(int argc, char const *argv[]){

    pthread_t tid;
    //struct serial_config 
    serial_con config1, config2, config3, config4;
    config1.baud_rate = 9600;
    config1.stop_bit = 0;
    config1.parity = 'Y';
    
    config2.baud_rate = 115000;
    config2.stop_bit = 1;
    config2.parity = 'Y';
    
    config3.baud_rate = 9600;
    config3.stop_bit = 1;
    config3.parity = 'N';
    
    config4.baud_rate = 12560;
    config4.stop_bit = 2;
    config4.parity = 'Y';
    
    pthread_create(&tid, NULL, serial_thread, &config1);
    pthread_create(&tid, NULL, serial_thread, &config2);
    pthread_create(&tid, NULL, serial_thread, &config3);
    pthread_create(&tid, NULL, serial_thread, &config4);
    
    sleep(1);
    return 0;
}