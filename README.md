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
- V<sub>out</sub> - measured voltage across R<sub>2</sub>  




R<sub>2</sub> = (V<sub>out</sub>*R<sub>1</sub>)/ (V<sub>in</sub>-V<sub>out</sub>) (voltage divider formula)

Since our rods are 0.6cm away from each other, we divide the Resistance by 0.6, so we get the resistance for one centimeter <br/>
R<sub>cm</sub> =  R<sub>2</sub>/0.6

### calculating EC 

Calculating the EC/cm and multiplying it by 10<sup>6</sup> to get μS/cm: <br/>
EC<sub>cm</sub> = 1/R<sub>cm</sub>*10<sup>6</sup>

Because the EC depends on the water temperature we need to compensate the temperature, to compare, we use the EC at 25°C: </br>
EC<sub>25</sub> = EC /( 1 + a (T - 25))

- T - temperature of the solution in 0.019°C (measured with the DS18B20)
- a - 0.019 °C (commonly used for nutrient solutions)

dont ask me how and why it works, it is completly stolen from Micheal Ratcliffe´s project...

### avoiding polarization
Although we are using a voltage divider, we cant turn it on for more than a few microseconds at a time as electrolysis begins and gives us wrong readings,  as bubbles form on the probe faces. We turn it on quickly take a measurement and turn it off again before the bubbles have time to form.

## 3D Model
I have no experience, what belongs to 3D printing, so I am only explaining my concept  

You need:
- 2mm diameter stainless steel rods
- DS18B20
- soldering iron
- solder
- some cable
- the 3D print

1. solder a cable to one of the ends of each rod
2. insert the DS18B20 and the steel roods, so it looks like this:
 
![stick_view](https://user-images.githubusercontent.com/80157991/170273426-40befbda-b42f-4e88-accd-4c0a76d9a8a2.png)


3. If you want it to be floating, you can fill the gaps with styropor by pressing the 3D-model into it, dont forget to glue it down
4. You can add two strings through these holes, so it is always floating at the same place, I kept the strings under tension by adding a suction cup connected with one end of the string to the bottom of the reservoir and connected the other end to the lid of my hydroponic reservoir.



![front_view](https://user-images.githubusercontent.com/80157991/170272913-3d3b8dd5-d585-4202-bf20-8e1e66999937.png)


