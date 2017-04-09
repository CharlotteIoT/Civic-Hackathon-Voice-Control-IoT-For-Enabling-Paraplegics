# Charlotte IoT: Wearable Temperature Monitor
## Tech Lead:  Mark Ingle 

## Description:  
There are lots of options on how the team does this.  One option would be to go with a wearable watch or something commercial to monitor the temperature.  You can also go in the direction where you build something with a one wire bus temp sensor.  The goal is to have something reliable that can post the person's temperature to the cloud so that we can control the blanket or fan in the bedroom.  Its an extra bonus if we can use it for the wheelchair controls for the fan or electric jacket on the wheelchair.  I do not think its as important on the wheelchair because Nick or Sean can control with speech and its not like sleeping where the temperature wakes you up.

## Analysis
The team looked at several off the shelf options for reading body temperature and potentially other body statistics that might help in making a decision on if a person is hot or cold.  We didn't find a lot of options for body temperature so we started to talk about if body temperature was really going to solve the problem.  We decided that body temperature might not vary all that much unless a person is sick so we focused on reading ambient temperature around the body.  The idea here is to read temperature and humidity in the bedroom and also on the lower/upper body under the blanket.  

## Outcome
We ended up using the Particle Photon and a DHT11 temp/humidity sensor to collect the data.  The sensor supports temperature and humidity and is placed into Particle Variables for a cloud service to read and make decisions on what to do the values.

## TODO
What should be addressed to enhance the data collection.
* Support multiple sensors.  Need to have more than one sensor under the blanket or on the body so the data sent up to the cloud service needs to have context on where the device is located
* Power - how will the devices be powered?  If they are placed under the blanket rather than on the body you might be able to use one device with multiple sensors and power from an outlet rather than battery.
* Enhance the data being collected like: min/max/average/begin/end values over time.  The device would calculate these values and send the results up to the cloud less frequently. 
* Document how to access the variables from Particle cloud.
* Research if there are any limitations with the Particle cloud variables or events that might keep us from having multiple sensors.
* Research if Flow or Logic Apps might be a good solution to read the sensor values and make a decision on turning on/off a fan or blanket.
* Research if the sensor should be smart in that it publishes events when thresholds are crossed or leave all those decisions for the cloud to make.