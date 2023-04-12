#include <DallasTemperature.h>
#include <NonBlockingDallas.h>// https://github.com/Gbertaz/NonBlockingDallas
#include <OneWire.h>
#include <LiquidCrystal.h>


const int ONE_WIRE_BUS  = 3;   //PIN of the Maxim DS18B20 temperature sensor
const int TIME_INTERVAL = 1500;//Time interval among sensor readings [milliseconds]
// LCD pin assignment for the Arduino R3
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;

OneWire oneWire( ONE_WIRE_BUS );
DallasTemperature dallasTemp( &oneWire );
NonBlockingDallas sensorDs18b20( &dallasTemp );// Create a new instance of the NonBlockingDallas class

void setup()
{
	delay( 1000 );
	Serial.begin( 115200 );
	if( !Serial )
		delay( 1000 );
  Serial.println( "Setup has begun." );

	// Initialize the sensor passing the resolution, unit of measure and reading interval [milliseconds]
	sensorDs18b20.begin( NonBlockingDallas::resolution_12, NonBlockingDallas::unit_F, TIME_INTERVAL );

	// Callbacks
	sensorDs18b20.onIntervalElapsed( handleIntervalElapsed );
	sensorDs18b20.onTemperatureChange( handleTemperatureChange );

	// Call the following function to request a new temperature reading without waiting for TIME_INTERVAL to elapse.
	sensorDs18b20.requestTemperature();
  Serial.println( "Setup has finished." );
}// End of the setup() function.

void loop()
{
	sensorDs18b20.update();
}// End of the loop() function.

// Invoked at every sensor reading (TIME_INTERVAL milliseconds)
void handleIntervalElapsed( float temperature, bool valid, int deviceIndex )
{
//	Serial.printf( "Sensor %d changed temperature: %f °F\n", deviceIndex, temperature );
	Serial.print( "Sensor : " );
	Serial.print( deviceIndex );
	Serial.print( " timer temperature " );
	Serial.println( temperature );
}// End of the handleIntervalElapsed() function.

//Invoked ONLY when the temperature changes between two sensor readings
void handleTemperatureChange( float temperature, bool valid, int deviceIndex )
{
//	Serial.printf( "Sensor %d changed temperature: %f °F\n", deviceIndex, temperature );
	Serial.print( "Sensor : " );
	Serial.print( deviceIndex );
	Serial.print( " changed temperature " );
	Serial.println( temperature );
}// End of the handleTemperatureChange() function.
