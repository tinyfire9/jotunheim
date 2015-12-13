CXX = g++
CC = g++
CFLAGS = -g -std=c++11

default: airline


airline: flight.o newFlight.o storageFlight.o \
		 plane.o newPlane.o storagePlane.o \
		 passenger.o newPassenger.o storagePassenger.o \
		 validity.o utilityPlane.o flightScheduleUtility.o utilityPassenger.o \
		 flightSchedule.o fleet.o passengers.o \
		 airline.o main.cpp

	$(CC) $(CFLAGS) -o airline flight.o newFlight.o storageFlight.o \
		   plane.o newPlane.o storagePlane.o \
		   passenger.o newPassenger.o storagePassenger.o \
		   validity.o utilityPlane.o flightScheduleUtility.o utilityPassenger.o \
		   flightSchedule.o fleet.o passengers.o \
		   airline.o main.cpp

# ./flightSchedule/flight
flight.o: flightSchedule/flight/flight.cpp flightSchedule/flight/flight.h
	$(CC) $(CFLAGS) -c flightSchedule/flight/flight.cpp
newFlight.o: flightSchedule/flight/newFlight.cpp flightSchedule/flight/newFlight.h
	$(CC) $(CFLAGS) -c flightSchedule/flight/newFlight.cpp
storageFlight.o: flightSchedule/flight/storageFlight.cpp flightSchedule/flight/storageFlight.h
	$(CC) $(CFLAGS) -c flightSchedule/flight/storageFlight.cpp

# ./fleet/plane
plane.o: fleet/plane/plane.cpp fleet/plane/plane.h
	$(CC) $(CFLAGS) -c fleet/plane/plane.cpp
newPlane.o: fleet/plane/newPlane.cpp fleet/plane/newPlane.h
	$(CC) $(CFLAGS) -c fleet/plane/newPlane.cpp
storagePlane.o: fleet/plane/storagePlane.cpp fleet/plane/storagePlane.h
	$(CC) $(CFLAGS) -c fleet/plane/storagePlane.cpp

# ./passengers/passenger
passenger.o: passengers/passenger/passenger.cpp passengers/passenger/passenger.h
	$(CC) $(CFLAGS) -c passengers/passenger/passenger.cpp
newPassenger.o: passengers/passenger/newPassenger.cpp passengers/passenger/newPassenger.h
	$(CC) $(CFLAGS) -c passengers/passenger/newPassenger.cpp
storagePassenger.o: passengers/passenger/storagePassenger.cpp passengers/passenger/storagePassenger.h
	$(CC) $(CFLAGS) -c passengers/passenger/storagePassenger.cpp

# ./utility
utility.o: utility/utility.h
	$(CC) $(CFLAGS) -c utility/utility.h
# ./utility/client
validity.o: utility/client/validity.cpp utility/client/validity.h
	$(CC) $(CFLAGS) -c utility/client/validity.cpp
# ./utility/fleet
utilityPlane.o: utility/fleet/utilityPlane.cpp utility/fleet/utilityPlane.h
	$(CC) $(CFLAGS) -c utility/fleet/utilityPlane.cpp
# ./utility/flightSchedule
flightScheduleUtility.o: utility/flightSchedule/flightScheduleUtility.cpp utility/flightSchedule/flightScheduleUtility.h
	$(CC) $(CFLAGS) -c utility/flightSchedule/flightScheduleUtility.cpp
# ./utility/passenger
utilityPassenger.o: utility/passenger/utilityPassenger.cpp utility/passenger/utilityPassenger.h
	$(CC) $(CFLAGS) -c utility/passenger/utilityPassenger.cpp

#./fleet
fleet.o: fleet/fleet.cpp fleet/fleet.h
	$(CC) $(CFLAGS) -c fleet/fleet.cpp
#./flightSchedule
flightSchedule.o: flightSchedule/flightSchedule.cpp flightSchedule/flightSchedule.h
	$(CC) $(CFLAGS) -c flightSchedule/flightSchedule.cpp
#./passengers
passengers.o: passengers/passengers.cpp passengers/passengers.h
	$(CC) $(CFLAGS) -c passengers/passengers.cpp

#./
airline.o: airline.cpp airline.h
	$(CC) $(CFLAGS) -c airline.cpp