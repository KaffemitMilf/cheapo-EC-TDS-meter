# cheapo-EC-TDS-meter

Hey, this is my version of Micheal Rattcliffe´s 3$ EC - PPM Meter. 
His meter is way better engineered than mine, so if you are looking for the most accurate, best build EC/TDS-meter go for his version.
It´s good enough for me/ my hydroponic nft system.

https://hackaday.io/project/7008-hacking-the-way-to-growing-food/log/24646-three-dollar-ec-ppm-meter-arduino


## problem
The electric plugs I used corroded everytime, so I designed a 3D-model, where I inserted two stainless steel rods and a DS18B20.

## working principle 

### units & more
EC - electrical conductivity equals 1/R (R-resistance) and is measured in Siemens - S

I like to use μS which equals S*10^−6, so it is easier to read.

Because the EC depends on the distance between the rods, we want to standarize it, so we use EC/cm or μS/cm.

### measuring the resistance 
To measure the resistance of the water, we use a simple voltage divider, the Arduino can only measure voltage but not resistance.
To get around that, we use a voltage divider, so we can measure a voltage and calculate the resistance.

