#include <Arduino.h>
#include "packet.h"

#define SER_DEBUG

//constructor
packet::packet(const uint16_t team_id){
	this->team_id = team_id;
	this->mission_time = 0;
	this->packet_count = 0;
	this->altitude = 0;
	this->pressure = 0;
	this->temperature = 0;
	this->voltage = 0;
	this->gps_time_utc = "2013-10-22T01:37:56+05:30";
	this->gps_lattitude = "0";
	this->gps_longitude = "0";
	this->gps_altitude = "0";
	this->gps_sats = "0";
	this->air_speed = 0;
	this->software_state = BOOT;
	this->particle_count = "0";
	this->pitch = 0;
	this->roll = 0;
}

String packet::toString(){
	String csv = String( 
	  String(this->team_id) + "," +
		String(this->mission_time) + "," +
		String(this->packet_count) + "," +
		String(this->altitude) + "," +
		String(this->pressure) + "," +
		String(this->temperature) + "," +
		String(this->voltage) + "," +
		this->gps_time_utc + "," +
		this->gps_lattitude + "," +
		this->gps_longitude + "," +
		this->gps_altitude + "," +
		this->gps_sats + "," +
		String(this->air_speed) + "," +
		String(this->software_state) + "," +
		String(this->particle_count) + "," +
		String(this->pitch) + "," +
		String(this->roll) ;
	);
	//this->_csv_string = csv;
  return csv;
}

void packet::display(){
	#ifdef SER_DEBUG
		Serial.println("======================= PACKET =======================");
		Serial.println("Packet Size\t\t:\t\t" + String(sizeof(*this)) + "\tBytes");
		Serial.println("------------------------------------------------------");
		Serial.println("Team ID\t\t\t:\t\t" + String(this->team_id));
		Serial.println("Mission Time\t\t:\t\t" + String(this->mission_time) + "\ts");
		Serial.println("Packet Count\t\t:\t\t" + String(this->packet_count) + "\tunits");
		Serial.println("Altitude\t\t:\t\t" + String(this->altitude) + "\tm");
		Serial.println("Pressure\t\t:\t\t" + String(this->pressure) + "\tPa");
		Serial.println("Temperature\t\t:\t\t" + String(this->temperature) + "\tC");
		Serial.println("Battery Voltage\t\t:\t\t" + String(this->voltage) + "\tV");
		Serial.println("GPS Time\t\t:\t\t" + this->gps_time_utc);
		Serial.println("GPS Lattitude\t\t:\t\t" + this->gps_lattitude + "\tE");
		Serial.println("GPS Longitude\t\t:\t\t" + this->gps_longitude + "\tN");
		Serial.println("GPS Altitude\t\t:\t\t" + this->gps_altitude + "\tm");
		Serial.println("GPS Sats\t\t:\t\t" + this->gps_sats + "\tunits");
		
		Serial.println("Air_speed\t\t:\t\t" + String(this->air_speed) + "\tRPM");
		Serial.println("Op state\t\t:\t\t" + String(this->software_state) + "");
		Serial.println("PM COUNT\t\t:\t\t" + this->particle_count + "\tmg/m^3");
		
		Serial.println("Pitch\t\t\t:\t\t" + String(this->pitch) + "\tdeg");
		Serial.println("Roll\t\t\t:\t\t" + String(this->roll) + "\tdeg");
		Serial.println("======================================================\n\n");
	#endif
}
