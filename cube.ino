#define CUBE_SIZE 3

int cube[CUBE_SIZE][CUBE_SIZE]={
    {A5, 6, 7},
    {A2, A3, A4},
    {A1, A0, 12}
};

int layers[CUBE_SIZE] = {2, 3, 5};

void setup() { 
  Serial.begin(9600);
 for (int i = 0; i < CUBE_SIZE; i++) {
     
     for (int j = 0; j < CUBE_SIZE; j++) {
         pinMode(cube[i][j], OUTPUT);
     }
 }
}


void light() {
    for (int i = 0; i < CUBE_SIZE; i++) {
        lightLayer(i);
    }
}

void switchOff() {
    for (int i = 0; i < CUBE_SIZE; i++) {
        switchOffLayer(i);
    }
}

void lightLayer(int z) {
    pinMode(layers[z], OUTPUT);    
     for (int i = 0; i < CUBE_SIZE; i++) {
        for (int j = 0; j < CUBE_SIZE; j ++) {
            digitalWrite(cube[i][j], HIGH);
        }  
    }  
}

void switchOffLayer (int z) {
    pinMode(layers[z], INPUT);    
     for (int i = 0; i < CUBE_SIZE; i++) {
        for (int j = 0; j < CUBE_SIZE; j ++) {
            digitalWrite(cube[i][j], LOW);
        }  
    } 
}

void lightCubeDelay (int delay_time) {  
    for (int i = 0; i < CUBE_SIZE; i++) {
        lightLayer(i);
        delay (delay_time);
        switchOffLayer(i);  
    }  
}

int array[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE] 
=  {
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    },
    {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    },
    {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    }
};


void lightLayerArray (int array[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE]) {    
    for (int x = 0; x < CUBE_SIZE; x++) {
        pinMode(layers[x], OUTPUT); 
        for (int y = 0; y < CUBE_SIZE; y++) {
            for (int z = 0; z < CUBE_SIZE; z++) {

                switch (array[x][y][z]) {
                    case 1:
                        digitalWrite (cube[y][z], HIGH);
                        break;
                    
                    default:
                        digitalWrite (cube[y][z], LOW);
                        break;
                }
            }
        }
        switchOffLayer(x);
    }
}

void getArray() {
    for (int i = 0; i< CUBE_SIZE; i++) {
        for (int j = 0; i< CUBE_SIZE; i++) {
            for (int k = 0; i< CUBE_SIZE; i++) {
                array[i][j][k] = Serial.read();
                Serial.println(array[i][j][k]);
            }
        }
    }
}






// String data;

void loop() {    
//способ со строками, при таком раскладе куб загорается только, если (data.length() == 1)
    String data;
    if (Serial.available() > 0) {
        data = Serial.readStringUntil("\n");

         if (data.length() == 2) {
            light();
        }
    }

    //способ с массивом char, при таком раскладе куб загорается ВСЕГДА сука такая ебучая
    // char buf[50];
    // int lenght = 0;

    // if (Serial.available() > 0) {
    //     int size = Serial.available();
    //     for (int i = 0; i < size; i++) {
    //         buf[i] = Serial.read();
    //         lenght++;
    //     }

    //     if (lenght == 2) {
    //         light();
    //     }
    // }       

    

    // while (Serial.available() == 0);
    // data = Serial.readStringUntil('\n');
    // Serial.setTimeout(0.01);

    // if (data.length() == 2) {
    //     light();
    // }

}
