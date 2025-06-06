// DatabaseManager.h - Handles Storing and Retrieving Booking Data
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <vector>

class DatabaseManager {
public:
    void saveBookingData(const std::string& bookingData);
    std::vector<std::string> loadBookings();
};

#endif // DATABASEMANAGER_H
