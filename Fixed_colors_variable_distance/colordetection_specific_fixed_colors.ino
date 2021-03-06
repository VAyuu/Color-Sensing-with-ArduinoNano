/*
Color sensing by tcs3200 and arduino nano.
*/

#define S0 5
#define S1 6
#define S2 7
#define S3 8
#define sensor_output 9

#define led_red_pin 19
#define led_green_pin 20
#define led_blue_pin 21

// color1 = red
int red_max_avg[] = {0,0,0} ;
int red_min_avg[] = {10000,10000,10000} ;
  
//color2 = green
int green_max_avg[] = {0,0,0} ;
int green_min_avg[] = {10000,10000,10000} ;
  
//color3 = blue
int blue_max_avg[] = {0,0,0} ;
int blue_min_avg[] = {10000,10000,10000} ;
  
//custom_color. you can add as many as you want here.
int custom1_max_avg[] = {0,0,0} ;
int custom1_min_avg[] = {10000,10000,10000} ;
int custom1_color[] = {255,0,255} ;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensor_output, INPUT);
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_red_pin, OUTPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  ///////caliberation
  Serial.print("Caliberating the color red!");
  Serial.print("Keep the red object ready in front of the sensor in the farthest distance you want in under 5 sec!");
  delay(5000) ;
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] > red_max_avg[0]){
      red_max_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] > red_max_avg[1]){
      red_max_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] > red_max_avg[2]){
      red_max_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color red!");
  Serial.print("Keep the red object ready in front of the sensor in the closest distance you want the device to work, in under 5 sec!");
  delay(5000) ;
  
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] < red_min_avg[0]){
      red_min_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] < red_min_avg[1]){
      red_min_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] < red_min_avg[2]){
      red_min_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color green!");
  Serial.print("Keep the green object ready in front of the sensor in the farthest distance you want the device to work in under 5 sec!");
  delay(5000);
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0};
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] > green_max_avg[0]){
      green_max_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] > green_max_avg[1]){
      green_max_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] > green_max_avg[2]){
      green_max_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color green!");
  Serial.print("Keep the green object ready in front of the sensor in the closest distance you want, in under 5 sec!");
  delay(5000);
  
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] < green_min_avg[0]){
      green_min_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] < green_min_avg[1]){
      green_min_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] < green_min_avg[2]){
      green_min_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color blue!");
  Serial.print("Keep the blue object ready in front of the sensor in the farthest distance you want the device to work in under 5 sec!");
  delay(5000) ;
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] > blue_max_avg[0]){
      blue_max_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] > blue_max_avg[1]){
      blue_max_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] > blue_max_avg[2]){
      blue_max_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color blue!");
  Serial.print("Keep the blue object ready in front of the sensor in the closest distance you want, in under 5 sec!");
  delay(5000) ;
  
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] < blue_min_avg[0]){
      blue_min_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] < blue_min_avg[1]){
      blue_min_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] < blue_min_avg[2]){
      blue_min_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color custom1!");
  Serial.print("Keep the costum1 color object ready in front of the sensor in the farthest distance you want the device to work in under 5 sec!");
  delay(5000) ;
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] > custom1_max_avg[0]){
      custom1_max_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] > custom1_max_avg[1]){
      custom1_max_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] > custom1_max_avg[2]){
      custom1_max_avg[2] = current_avg[2] ;
    }
  }
  
  Serial.print("Caliberating the color custom1!");
  Serial.print("Keep the custom1 color object ready in front of the sensor in the closest distance you want, in under 5 sec!");
  delay(5000) ;
  
  
  for(int i=1;i<21;i++){
    
    int current_avg[] = {0,0,0} ;
    
    for(int j=1;j<101;j++){
      
      int frequency_red = 0 ;
      int frequency_green = 0 ;
      int frequency_blue = 0 ;
      
      // Setting red filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      // Reading the output frequency
      frequency_red = pulseIn(sensor_output, LOW);
      current_avg[0] = current_avg[0] + frequency_red ;
      delay(50) ;
      
      // Setting green filtered photodiodes to be read
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_green = pulseIn(sensor_output, LOW);
      current_avg[1] = current_avg[1] + frequency_red ;
      delay(50) ;
      
      // Setting blue filtered photodiodes to be read
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      // Reading the output frequency
      frequency_blue = pulseIn(sensor_output, LOW);
      current_avg[2] = current_avg[2] + frequency_blue ;
      delay(50) ;
      
    }
    
    current_avg[0] = (current_avg[0]/100) ;
    current_avg[1] = (current_avg[1]/100) ;
    current_avg[2] = (current_avg[2]/100) ;
    
    if(current_avg[0] < custom1_min_avg[0]){
      custom1_min_avg[0] = current_avg[0] ;
    }
    
    if(current_avg[1] < custom1_min_avg[1]){
      custom1_min_avg[1] = current_avg[1] ;
    }
    
    if(current_avg[2] < custom1_min_avg[2]){
      custom1_min_avg[2] = current_avg[2] ;
    }
  
  Serial.begin(9600);
  }
}

void loop( ) {
  
  int red_frequency_avg = 0 ;
  int green_frequency_avg = 0 ;
  int blue_frequency_avg = 0 ;
  
  //reading the color
  Serial.print("Please keep the object for which color is to sensed!, in 5 seconds") ;
  delay(5000) ;
  
  for(int i=1;i<1001;i++){
    
    // reading data from red filters.
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    red_frequency_avg = red_frequency_avg + pulseIn(sensor_output, LOW);
    delay(50) ;
  
    //reading data from green filters.
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    green_frequency_avg = green_frequency_avg + pulseIn(sensor_output, LOW);
    delay(50) ;
  
    //reading data from blue filters.
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blue_frequency_avg = blue_frequency_avg + pulseIn(sensor_output, LOW);
    delay(50) ;
  }
  
  red_frequency_avg = (red_frequency_avg/1000) ;
  green_frequency_avg = (green_frequency_avg/1000) ;
  blue_frequency_avg = (blue_frequency_avg/1000) ;
  
  //deciding the color of the object.
  //red
  if(red_min_avg[0] - 5 < red_frequency_avg && red_frequency_avg < red_max_avg[0] + 5 && red_min_avg[1]-5 < green_frequency_avg && green_frequency_avg < red_max_avg[1] && red_min_avg[2]-5 < blue_frequency_avg && blue_frequency_avg < red_max_avg[2]) {
    Serial.print("The color is red!") ;
    led_color(255,0,0) ; //color is red here. 5 is the tolerence in the avg and 5 is too high tolerance.
  }
  
  if(green_min_avg[0] - 5 < red_frequency_avg && red_frequency_avg < green_max_avg[0] + 5 && green_min_avg[1]-5 < green_frequency_avg && green_frequency_avg < green_max_avg[1] && green_min_avg[2]-5 < blue_frequency_avg && blue_frequency_avg < green_max_avg[2]) {
    Serial.print("The color is green!") ;
    led_color(0,255,0) ;//color is green
  }
  
  if(blue_min_avg[0] - 5 < red_frequency_avg && red_frequency_avg < blue_max_avg[0] + 5 && blue_min_avg[1]-5 < green_frequency_avg && green_frequency_avg < blue_max_avg[1] && blue_min_avg[2]-5 < blue_frequency_avg && blue_frequency_avg < blue_max_avg[2]) {
    Serial.print("The color is blue!") ;
    led_color(0,0,255) ;//color is blue
  }
  
  if(custom1_min_avg[0] - 5 < red_frequency_avg && red_frequency_avg < custom1_max_avg[0] + 5 && custom1_min_avg[1]-5 < green_frequency_avg && green_frequency_avg < custom1_max_avg[1] && custom1_min_avg[2]-5 < blue_frequency_avg && blue_frequency_avg < custom1_max_avg[2]) {
    Serial.print("The color is custom1!") ;
    led_color(custom1_color[0],custom1_color[1],custom1_color[2]) ; //color is red here 5 is the tolerence in the avg and 5 is too high tolerance.
  }
}

void led_color(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(led_red_pin, red_light_value);
  analogWrite(led_green_pin, green_light_value);
  analogWrite(led_blue_pin, blue_light_value);
}
