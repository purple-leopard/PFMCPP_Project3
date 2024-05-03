/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




/*
paste your code below
*/

struct Dog
{
    Dog();
    float weight = 10.0f;
    float height = 0.5f;
    int ageInYears = 3;
    std::string furColour = "brown";
    std::string breed = "Beagle";

    struct DogCollar
    {
        DogCollar();
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

Dog::Dog()
{
    std::cout << "Dog being constructed\n";
}

Dog::DogCollar::DogCollar()
{
    std::cout << "DogCollar being constructed\n";
}

void Dog::DogCollar::attachLeash(const std::string& leashType, bool isRetractable)
{
    std::cout << "leash type: " << leashType << ", retractable: " << isRetractable << "\n";
}

void Dog::DogCollar::remove(bool clipRelease)
{
    std::cout << (clipRelease ? "clip released\n" : "clip not released\n");
}

bool Dog::DogCollar::adjustFit(float newSize, float minSize, float maxSize) 
{
    if (newSize >= minSize && newSize <= maxSize) 
    {
        length = newSize;
        std::cout << "adjustment successful\n";
        return true;
    }
    std::cout << "adjustment unsuccessful\n";
    return false;
}

void Dog::barkAtPostman() 
{
    std::cout << "bark\n";
}

void Dog::fetchBall()
{
    std::cout << "fetch\n";
}

bool Dog::tryNewCollar(DogCollar newCollar) 
{
    if (newCollar.length >= 10.0f && newCollar.length <= 20.0f) 
    {
        currentCollar = newCollar;
        std::cout << "collar fits, replace original collar with new collar\n";
        return true;
    }
    std::cout << "collar doesn't fit, keep original collar\n";
    return false;
}

struct Laptop
{
    Laptop();
    std::string brand = "Apple";
    std::string model = "Macbook";
    std::string operatingSystemVersion = "Snow Leopard";
    int memoryCapacity = 16;
    int numberOfProcessorCores = 4;
    
    struct Battery
    {
        Battery();
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

Laptop::Laptop()
{
    std::cout << "Laptop being constructed\n";
}

Laptop::Battery::Battery()
{
    std::cout << "Battery being constructed\n";
}

bool Laptop::Battery::charge(float chargeToLevel) 
{
    float chargeLevel = 75.0f;
    std::cout << "battery charging to level: " << chargeToLevel << "%\n";
    return chargeLevel >= chargeToLevel;
}

float Laptop::Battery::checkCapacityRemaining(const std::string& fuelGuageAlgorithm) 
{
    float capacityRemaining = 1000.0f;
    std::cout << "checking battery capacity remaining using " << fuelGuageAlgorithm << "\n";
    return capacityRemaining;
}

void Laptop::Battery::limitChargeCurrent(float inputCurrent, float temperatureLimit) 
{
    float temperature = 38.0f;
    if (inputCurrent > maxChargeCurrent || temperature > temperatureLimit) 
    {
        inputCurrent = maxChargeCurrent;
        std::cout << "charge current limited to " << maxChargeCurrent << "\n";
    }
}

void Laptop::replaceBattery(Battery newBattery) 
{
    currentBattery = newBattery;
    std::cout << "battery replaced with type: " << newBattery.type << "\n";
}

bool Laptop::launchProgram(const std::string& programName) 
{
    std::cout << "launching program: " << programName << "\n";
    return true;
}

bool Laptop::invokeCompiler() 
{
    std::cout << "compiler invoked" << "\n";
    return true;
}

struct WeatherSatellite
{
    WeatherSatellite();
    int numberOfSolarPanels = 8;
    std::string radiationHardeningType = "Standard";
    double attitude = 360.0;
    double orbitalVelocity = 7.8;
    float antennaCenterFrequency = 2.4f;
    void switchImagingModality();
    int transmitDataToGroundStation();
    float monitorBatteryChargeLevel();
};

WeatherSatellite::WeatherSatellite()
{
    std::cout << "WeatherSatellite being constructed\n";
}

void WeatherSatellite::switchImagingModality()
{
    std::cout << "switching imaging modality from visible to infrared\n";
}

int WeatherSatellite::transmitDataToGroundStation()
{
    int numberOfImagesTransmitted = 500;
    std::cout << "transmitted " << numberOfImagesTransmitted << " images\n";
    return numberOfImagesTransmitted;
}

float WeatherSatellite::monitorBatteryChargeLevel()
{
    float chargeLevel = 75.0f;
    std::cout << "current battery charge level is " << chargeLevel << "%\n";
    return chargeLevel;
}

struct FilmCamera
{
    FilmCamera();
    std::string viewfinderType = "Waist Level";
    std::string lensMountType = "FD";
    float maximumShutterSpeed = 0.001f;
    float weight = 1.2f;
    std::string brand = "Canon";
    void releaseShutter();
    void advanceFilm();
    void engageLightmeter();
};

FilmCamera::FilmCamera()
{
    std::cout << "FilmCamera being constructed\n";
}

void FilmCamera::releaseShutter()
{
    std::cout << "shutter released\n";
}

void FilmCamera::advanceFilm()
{
    std::cout << "film advanced to the next frame\n";
}

void FilmCamera::engageLightmeter()
{
    std::cout << "lightmeter engaged\n";
}

struct SecuritySystem
{
    SecuritySystem();
    int numberOfCameras = 4;
    float motionSensorSensitivity = 5.0f;
    float alarmLoudness = 110.0f;
    int backupBatteryCapacity = 10000;
    std::string connectivityType = "WiFi";
    bool detectIntrusion();
    int recordVideo();
    void sendAlertToSmartphone();
};

SecuritySystem::SecuritySystem()
{
    std::cout << "SecuritySystem being constructed\n";
}

bool SecuritySystem::detectIntrusion()
{
    std::cout << "intrusion detected with sensitivity level: " << motionSensorSensitivity << "\n";
    return true; 
}

int SecuritySystem::recordVideo()
{
    int numberOfFramesRecorded = 5;
    std::cout << "recording\n";
    return numberOfFramesRecorded;
}

void SecuritySystem::sendAlertToSmartphone()
{
    std::cout << "alert sent to smartphone over " << connectivityType << "\n";
}

struct LightingControl
{
    LightingControl();
    int numberOfConnectedLights = 10;
    int energyConsumption = 500;
    std::string colourTemperature = "5000K";
    int brightnessLevels = 10;
    int motionDetectionSensitivity = 3;
    void adjustBrightness(int level);
    void adjustLightColour(const std::string& colour);
    bool detectMotion();
};

LightingControl::LightingControl()
{
    std::cout << "LightingControl being constructed\n";
}

void LightingControl::adjustBrightness(int level)
{
    std::cout << "brightness adjusted to level " << level << "\n";
}

void LightingControl::adjustLightColour(const std::string& colour)
{
    std::cout << "light colour adjusted to " << colour << "\n";
}

bool LightingControl::detectMotion()
{
    std::cout << "motion detected with sensitivity: " << motionDetectionSensitivity << "\n";
    return true;
}

struct HVACSystem
{
    HVACSystem();
    float thermostatAccuracy = 0.1f;
    std::string filterQuality = "HEPA";
    std::string energyEfficiencyRating = "A++";
    int coolingCapacity = 5000;
    int heatingCapacity = 5000;
    void increaseRoomTemperature(float degrees);
    void filterIndoorAir();
    void optimiseEnergyUse();
};

HVACSystem::HVACSystem()
{
    std::cout << "HVACSystem being constructed\n";
}

void HVACSystem::increaseRoomTemperature(float degrees)
{
    std::cout << "room temperature increased to " << degrees << " degrees\n";
}

void HVACSystem::filterIndoorAir()
{
    std::cout << "indoor air filtered using " << filterQuality << " filter\n";
}

void HVACSystem::optimiseEnergyUse()
{
    std::cout << "energy use optimised for efficiency rating: " << energyEfficiencyRating << "\n";
}

struct EntertainmentSystem
{
    EntertainmentSystem();
    int numberOfSpeakers = 5;
    int screenSize = 55;
    std::string supportedVideoFormat = "4K UHD";
    int maximumAudioOutputLevel = 120;
    std::string brand = "Sony";
    void playVideoContent();
    float streamAudioContent();
    bool connectToBluetoothDevice();
};

EntertainmentSystem::EntertainmentSystem()
{
    std::cout << "EntertainmentSystem being constructed\n";
}

void EntertainmentSystem::playVideoContent()
{
    std::cout << "playing video\n";
}

float EntertainmentSystem::streamAudioContent()
{
    float sample = 0.78f;
    std::cout << "streaming audio\n";
    return sample;
}

bool EntertainmentSystem::connectToBluetoothDevice()
{
    std::cout << "bluetooth pairing complete\n";
    return true;
}

struct SmartAppliance
{
    SmartAppliance();
    std::string washCycleType = "Cotton";
    float energyConsumptionPerCycle = 0.5f;
    float waterUsagePerCycle = 10.0f;
    std::string model = "WashMaster 3000";
    std::string smartHomeCompatibility = "HomeKit";
    void washClothes();
    void optimisePowerUsageBasedOnLoad();
    bool sendAlertToHomeowners();
};

SmartAppliance::SmartAppliance()
{
    std::cout << "SmartAppliance being constructed\n";
}

void SmartAppliance::washClothes()
{
    std::cout << model << " wash in progress\n";
}

void SmartAppliance::optimisePowerUsageBasedOnLoad()
{
     std::cout << "optimising power usage for " << washCycleType << " cycle\n";   
}

bool SmartAppliance::sendAlertToHomeowners()
{
    std::cout << "alert sent successfuly\n";
    return true;
}

struct SmartHomeSystem
{
    SmartHomeSystem();
    SecuritySystem securitySystem;
    LightingControl lightingControl;
    HVACSystem hvacSystem;
    EntertainmentSystem entertainmentSystem;
    SmartAppliance smartAppliance;
    float monitorHomeTemperature();
    void controlLighting(const std::string& roomId);
    void triggerAlarmSound();
};

SmartHomeSystem::SmartHomeSystem()
{
    std::cout << "SmartHomeSystem being constructed\n";
}

float SmartHomeSystem::monitorHomeTemperature()
{
    float currentTemperature = 19.8f;
    std::cout << "current home temperature: " << currentTemperature << " degrees celsius\n";
    return currentTemperature;
}

void SmartHomeSystem::controlLighting(const std::string &roomId)
{
    std::cout << "decrease light intensity based on ambient light in room: " << roomId << "\n";
}

void SmartHomeSystem::triggerAlarmSound()
{
    std::cout << "triggering alarm sound\n";
}

int main()
{
    Example::main(); //do not delete this line

    Dog::DogCollar pinkCollar;
    Dog jackRussel;
    
    jackRussel.barkAtPostman();
    jackRussel.fetchBall();
    jackRussel.tryNewCollar(pinkCollar);
    jackRussel.currentCollar.attachLeash("gangster", true);
    jackRussel.currentCollar.adjustFit(15, 10.0f, 20.0f);
    jackRussel.currentCollar.remove(true);
 
    std::cout << "good to go!" << std::endl;
}
