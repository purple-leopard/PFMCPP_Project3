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
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;

    struct Foot
    {
        void stepForward();
        int stepSize();
    };

    void run(int howFast, bool startWithLeftFoot);

    Foot leftFoot;
    Foot rightFoot;
};

void Person::Foot::stepForward()
{
    std::cout << "step\n";
}

int Person::Foot::stepSize()
{
    return 1;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTravelled += howFast * (leftFoot.stepSize() + rightFoot.stepSize());
}
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
    float weight = 10.0f;
    float height = 0.5f;
    int ageInYears = 3;
    std::string furColour = "brown";
    std::string breed = "Beagle";

    struct DogCollar
    {
        std::string material = "leather";
        std::string color = "red";
        std::string dogName = "BUSTER";
        float length = 15.0f;
        float width = 0.5f;

        void attachLeash(const std::string& leashType = "standard", bool isRetractable = false);
        void remove(bool clipRelease = true);
        bool adjustFit(float newSize, float minSize = 10.0f, float maxSize = 20.0f);
    };

    void barkAtPostman();
    void fetchBall();
    bool tryNewCollar(DogCollar newCollar);

    DogCollar currentCollar;
};

struct Laptop
{
    std::string brand = "Apple";
    std::string model = "Macbook";
    std::string operatingSystemVersion = "Snow Leopard";
    int memoryCapacity = 16;
    int numberOfProcessorCores = 4;
    
    struct Battery
    {
        std::string type = "Li-ion";
        float capacity = 5000.0f;
        int chargeCycles = 1000;
        float maxChargeCurrent = 2.0f;
        float voltage = 18.0f;

        bool charge(float chargeToLevel = 100.0f);
        float checkCapacityRemaining(const std::string& fuelGuageAlgorithm = "ModelGauge");
        void limitChargeCurrent(float inputCurrent, float temperatureLimit = 85.8f);
    };

    void replaceBattery(Battery newBattery);
    bool launchProgram(const std::string& programName);
    bool invokeCompiler();

    Battery currentBattery;
};

struct WeatherSatellite
{
    int numberOfSolarPanels = 8;
    std::string radiationHardeningType = "Standard";
    double attitude = 360.0;
    double orbitalVelocity = 7.8;
    float antennaCenterFrequency = 2.4f;
    void switchImagingModality();
    int transmitDataToGroundStation();
    float monitorBatteryChargeLevel();
};

struct FilmCamera
{
    std::string viewfinderType = "Waist Level";
    std::string lensMountType = "FD";
    float maximumShutterSpeed = 0.001f;
    float weight = 1.2f;
    std::string brand = "Canon";
    void releaseShutter();
    void advanceFilm();
    void engageLightmeter();
};

struct SecuritySystem
{
    int numberOfCameras = 4;
    float motionSensorSensitivity = 5.0f;
    float alarmLoudness = 110.0f;
    int backupBatteryCapacity = 10000;
    std::string connectivityType = "WiFi";
    bool detectIntrusion();
    int recordVideo();
    void sendAlertToSmartphone();
};

struct LightingControl
{
    int numberOfConnectedLights = 10;
    int energyConsumption = 500;
    std::string colourTemperature = "5000K";
    int brightnessLevels = 10;
    int motionDetectionSensitivity = 3;
    void adjustBrightness(int level);
    void adjustLightColour(const std::string& colour);
    bool detectMotion();
};

struct HVACSystem
{
    float thermostatAccuracy = 0.1f;
    std::string filterQuality = "HEPA";
    std::string energyEfficiencyRating = "A++";
    int coolingCapacity = 5000;
    int heatingCapacity = 5000;
    void increaseRoomTemperature(float degrees);
    void filterIndoorAir();
    void optimiseEnergyUse();
};

struct EntertainmentSystem
{
    int numberOfSpeakers = 5;
    int screenSize = 55;
    std::string supportedVideoFormat = "4K UHD";
    int maximumAudioOutputLevel = 120;
    std::string brand = "Sony";
    void playVideoContent();
    float streamAudioContent();
    bool connectToBluetoothDevice();
};

struct SmartAppliance
{
    std::string washCycleType = "Cotton";
    float energyConsumptionPerCycle = 0.5f;
    float waterUsagePerCycle = 10.0f;
    std::string model = "WashMaster 3000";
    std::string smartHomeCompatibility = "HomeKit";
    void washClothes();
    void optimisePowerUsageBasedOnLoad();
    bool sendAlertToHomeowners();
};

struct SmartHomeSystem
{
    SecuritySystem securitySystem;
    LightingControl lightingControl;
    HVACSystem hvacSystem;
    EntertainmentSystem entertainmentSystem;
    SmartAppliance smartAppliance;
    float monitorHomeTemperature();
    void controlLighting(const std::string& roomId);
    void triggerAlarmSound();
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
