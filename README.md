# cheapo-EC-TDS-meter

Hey, this is my version of Micheal Rattcliffe´s 3$ EC - PPM Meter. 
His meter is way better engineered than mine, so if you are looking for the most accurate, best build EC/TDS-meter go for his version.
It´s good enough for me/ my hydroponic nft system.

https://hackaday.io/project/7008-hacking-the-way-to-growing-food/log/24646-three-dollar-ec-ppm-meter-arduino


## problem
The electric plugs I used corroded everytime, so I designed a 3D-model, where I inserted two stainless steel rods and a DS18B20.

## working principle 

### units & more
EC - electrical conductivity equals 1/R (R-resistance) and is measured in Siemens - S<br/>
I like to use μS which equals S*10^<sup>−6</sup>, so it is easier to read.

Because the EC depends on the distance between the rods, we want to standarize it, so we use EC/cm or μS/cm.

### measuring the resistance 
To measure the resistance of the water, we use a simple voltage divider, the Arduino can only measure voltage but not resistance.
To get around that, we use a voltage divider, so we can measure a voltage and calculate the resistance.

![2a379f0b-66db-470f-b54a-1d5732d96486](https://imgs.search.brave.com/iXdzhoNWDpuSUs0TFis7hd0g7asi3qvVCDJkgN1TsfQ/rs:fit:1200:1200:1/g:ce/aHR0cHM6Ly9jZG4u/aW5jaGNhbGN1bGF0/b3IuY29tL3dwLWNv/bnRlbnQvdXBsb2Fk/cy8yMDE5LzAyL3Zv/bHRhZ2UtZGl2aWRl/ci5wbmc)
(simple voltage divider)

- R<sub>1</sub>resistor (R<sub>1</sub>) - known resistance
- R<sub>2</sub> resistor (R<sub>2</sub>) - unknown resistor, resistance accross the stainless steel rods, water
- V<sub>in</sub> - input voltage
- V<sub>out</sub> - measured voltage between R<sub>2</sub> and - 




R<sub>2</sub> = (V<sub>out</sub>*R<sub>1</sub>)/ (V<sub>in</sub>-V<sub>out</sub>) (voltage divider formula)

Since our rods are 0.7cm away from each other, we divide the Resistance by 0.7, so we get the resistance for one centimeter <br/>
R<sub>cm</sub> =  R<sub>2</sub>/0.7

### calculating EC 

Calculating the EC/cm and multiplying it by 10<sup>6</sup> to get μS/cm: <br/>
EC<sub>cm</sub> = 1/R<sub>cm</sub>*

Because the EC depends on the water temperature we need to compensate the temperature, to compare, we use the EC at 25°C: </br>
EC<sub>25</sub> = EC /( 1 + a (T - 25))

- T - temperature of the solution in 0.019°C (measured with the DS18B20)
- a - 0.019 °C (commonly used for nutrient solutions)

dont ask me how and why it works, it is completly stolen from Micheal Ratcliffe´s project...

### avoiding polarization
To avoid the polarization and electrolysis of the liquid, we only measure in a short pulse. Otherwise the resistance will change.
Instead of using the 5V pin, I used a pin, which I can switch on/off.

 


