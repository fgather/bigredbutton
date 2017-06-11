# ESP32 Red Button

## What does it do?

The BigRedButton is an ESP32 based, battery powered button which is publishing Wifi messages when the it is pressed. 
Supported message protocols are: UDP, HTTP, HTTPS, MQTT. 

## Usage

To use the BigRedButton, turn the key into the "on"-position  and wait for a few seconds until it is connected to your Wifi. 
Then just press it :)

## Configuration

To configure the BigRedButton keep the Button pressed for a few seconds while turning it on. 
It should now boot in the configuration mode. In configuration mode the button acts as an Wifi access point with the name "BigRedButton". 
Connect to it (password is "BigRedButton") and open 192.168.1.1 in a browser. 
You will see a simple web page allowing you to change various settings. 

## Compiling/Uploading

The firmware can be compiled in and uploaded with PlatformIO. 

## Setup Hardware

ESP32 pin mapping:
Pin 17 -> Button Pin, active low
