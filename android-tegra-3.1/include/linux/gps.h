/*
 * gps.h
 *
 *  Created on: Nov 30, 2012
 */

#ifndef GPS_H_
#define GPS_H_

struct gps_location {
	double latitude;
	double longitude;
	float  accuracy;  /* in meters */
};

/* Embeds a timestamp with the location */
struct kernel_gps {
	/* A latitude, longitude location along with accuracy  */
	struct gps_location loc;
	/* The time when this location was updated. */
	struct timespec timestamp;
};

/* Represenation of the GPS information on disk */
struct gps_on_disk {
	struct gps_location loc;
	unsigned int age;
};

/* This is a public interface method. It's meant to be available
 * in the kernel as a means of accessing current gps data. */
void get_current_location(struct kernel_gps *result);

#endif /* GPS_H_ */
