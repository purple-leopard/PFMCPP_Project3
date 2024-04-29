 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
*/

struct Dog
{
    // weight (float)
    float weight = 10.0f;
    // height (float)
    float height = 0.5f;
    // age in years (int)
    int ageInYears = 3;
    // fur colour (std::string)
    std::string furColour = "brown";
    // breed (std::string)
    std::string breed = "Beagle";

    struct DogCollar
    {
        std::string material = "leather";
        std::string color = "red";
        std::string dogName = "BUSTER";
        float length = 15.0f;
        float width = 0.5f;

        // Actions
        void attachLeash(const std::string& leashType = "standard", bool isRetractable = false);
        void remove(bool clipRelease = true);
        bool adjustFit(float newSize, float minSize = 10.0f, float maxSize = 20.0f);  // returns true if adjustment is successful
    };

    // 3 things it can do:
    // bark at postman
    void barkAtPostman();
    // fetch ball
    void fetchBall();
    // try new collar
    bool tryNewCollar(DogCollar newCollar); // return whether the new collar fits

    DogCollar currentCollar;
};

struct Laptop
{
    // brand (std::string)
    std::string brand = "Apple";
    // model (std::string)
    std::string model = "Macbook";
    // operating system version (std::string)
    std::string operatingSystemVersion = "Snow Leopard";
    // memory capacity (int) // if measured in GB
    int memoryCapacity = 16;
    // number of processor cores (int)
    int numberOfProcessorCores = 4;
    
    struct Battery
    {
        std::string type = "Li-ion";
        float capacity = 5000.0f;
        int chargeCycles = 1000;
        float maxChargeCurrent = 2.0f;
        float voltage = 18.0f;

        // Actions
        bool charge(float chargeToLevel = 100.0f); // returns true if battery finished charging
        float checkCapacityRemaining(const std::string& fuelGuageAlgorithm = "ModelGauge"); // returns percentage of capacity remaining
        void limitChargeCurrent(float inputCurrent, float temperatureLimit = 85.8f);
    };

    // 3 things it can do:
    // replace battery 
    void replaceBattery(Battery newBattery);
    // launch program
    bool launchProgram(const std::string& programName); // returns true if program launches successfully
    // invoke compiler
    bool invokeCompiler(); // returns true if compiler is invoked successfully

    Battery currentBattery;
};

struct WeatherSatellite
{
    // number of solar panels (int)
    int numberOfSolarPanels = 8;
    // radiation hardening type (std::string)
    std::string radiationHardeningType = "Standard";
    // attitude (double)
    double attitude = 360.0;
    // orbital velocity (double)
    double orbitalVelocity = 7.8;
    // antenna center frequency (float)
    float antennaCenterFrequency = 2.4f;
    // 3 things it can do:
    // switch imaging modality 
    void switchImagingModality();
    // transmit data to ground station
    int transmitDataToGroundStation(); // returns number of images transmitted
    // monitor battery charge level
    float monitorBatteryChargeLevel(); // returns battery charge level
};

struct FilmCamera
{
    // viewfinder type (std::string)
    std::string viewfinderType = "Waist Level";
    // lens mount type (std::string)
    std::string lensMountType = "FD";
    // maximum shutter speed (float)
    float maximumShutterSpeed = 0.001f;
    // weight (float)
    float weight = 1.2f;
    // brand (std::string)
    std::string brand = "Canon";
    // 3 things it can do:
    // release shutter
    void releaseShutter();
    // advance film
    void advanceFilm();
    // engage lightmeter
    void engageLightmeter();
};

struct SecuritySystem
{
    // number of cameras (int)
    int numberOfCameras = 4;
    // motion sensor sensitivity in meters (float)
    float motionSensorSensitivity = 5.0f;
    // alarm loudness in dB (float)
    float alarmLoudness = 110.0f;
    // backup battery capacity in mAh (int)
    int backupBatteryCapacity = 10000;
    // connectivity type (std::string)
    std::string connectivityType = "WiFi";
    // 3 things it can do:
    // detect intrusion
    bool detectIntrusion(); // returns true if an intrusion is detected
    // record video
    int recordVideo(); // returns number of frames recorded
    // send alert to smartphone
    void sendAlertToSmartphone();
};

struct LightingControl
{
    // number of connected lights (int)
    int numberOfConnectedLights = 10;
    // energy consumption in watts (int)
    int energyConsumption = 500;
    // colour temperature (std::string)
    std::string colourTemperature = "5000K";
    // brightness levels (int)
    int brightnessLevels = 10;
    // motion detection sensitivity (int)
    int motionDetectionSensitivity = 3;
    // 3 things it can do:
    // adjust brightness
    void adjustBrightness(int level);
    // adjust light colour
    void adjustLightColour(const std::string& colour);
    // detect motion
    bool detectMotion(); // returns true if motion is detected
};

struct HVACSystem
{
    //  thermostat accuracy (float)
    float thermostatAccuracy = 0.1f;
    //  filter quality (std::string)
    std::string filterQuality = "HEPA";
    //  energy efficiency rating (std::string)
    std::string energyEfficiencyRating = "A++";
    //  cooling capacity in BTUs (int)
    int coolingCapacity = 5000;
    //  heating capacity in BTUs (int)
    int heatingCapacity = 5000;
    // 3 things it can do:
    // increase room temperature
    void increaseRoomTemperature(float degrees);
    // filter indoor air
    void filterIndoorAir();
    // optimise energy use
    void optimiseEnergyUse();
};

struct EntertainmentSystem
{
    // number of speakers (int)
    int numberOfSpeakers = 5;
    // screen size (int)
    int screenSize = 55;
    // supported video format (std::string)
    std::string supportedVideoFormat = "4K UHD";
    // maximum audio output level (int)
    int maximumAudioOutputLevel = 120;
    // brand (std::string)
    std::string brand = "Sony";
    // 3 things it can do:
    // play video content
    void playVideoContent();
    // stream audio content
    float streamAudioContent(); // returns audio data
    // connect to bluetooth device
    bool connectToBluetoothDevice(); // returns true if Bluetooth device is connected successfully
};

struct SmartAppliance
{
    // wash cycle type (std::string)
    std::string washCycleType = "Cotton";
    // energy consumption per cycle in kWh (float)
    float energyConsumptionPerCycle = 0.5f;
    // water usage per cycle in l (float)
    float waterUsagePerCycle = 10.0f;
    // model (std::string)
    std::string model = "WashMaster 3000";
    // smart home compatibility (std::string)
    std::string smartHomeCompatibility = "HomeKit";
    // 3 things it can do:
    // wash clothes
    void washClothes();
    // optimise power usage based on load
    void optimisePowerUsageBasedOnLoad();
    // send alert to homeowners
    bool sendAlertToHomeowners(); // returns true if alert is sent successfully
};

struct SmartHomeSystem
{
    // Security System
    SecuritySystem securitySystem;
    // Lighting Control
    LightingControl lightingControl;
    // HVAC System
    HVACSystem hvacSystem;
    // Entertainment System
    EntertainmentSystem entertainmentSystem;
    // Smart Appliance
    SmartAppliance smartAppliance;
    // 3 things it can do:
    // monitor home temperature
    float monitorHomeTemperature(); // returns temperature
    // control lighting
    void controlLighting(const std::string& roomId);
    // trigger alarm sound
    void triggerAlarmSound();
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
