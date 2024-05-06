/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




/*
paste your code below
*/

struct Dog
{
    Dog();
    float weight;
    float height;
    int ageInYears;
    std::string furColour;
    std::string breed;

    struct DogCollar
    {
        DogCollar();
        std::string material;
        std::string color;
        std::string dogName;
        float length;
        float width;

        void attachLeash(const std::string& leashType = "standard", bool isRetractable = false);
        void remove(bool clipRelease = true);
        bool adjustFit(float newSize, float minSize = 10.0f, float maxSize = 20.0f);
    };

    void barkAtPostman();
    void fetchBall();
    bool tryNewCollar(DogCollar newCollar);

    DogCollar currentCollar;
};

Dog::Dog() : weight(10.0f), height(0.5f), ageInYears(3), furColour("brown"), breed("Jack Russel")
{
    std::cout << "Dog being constructed\n";
}

Dog::DogCollar::DogCollar() : material("leather"), color("red"), dogName("BUSTER"), length(15.0f), width(0.5f)
{
    std::cout << "DogCollar being constructed\n";
}

void Dog::DogCollar::attachLeash(const std::string& leashType, bool isRetractable)
{
    std::cout << "leash material: " << material << ", leash type: " << leashType << ", leash retractable: " << isRetractable << "\n";
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
    std::cout << furColour << " colour dog is barking at the postman\n";
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
    std::string model;
    std::string operatingSystemVersion = "Snow Leopard";
    int memoryCapacity = 16;
    int numberOfProcessorCores = 4;
    
    struct Battery
    {
        Battery();
        std::string type = "Li-ion";
        float capacity;
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

Laptop::Laptop() : model("Macbook")
{
    std::cout << "Laptop being constructed\n";
}

Laptop::Battery::Battery() : capacity(5000.0f)
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
    std::cout << "checking battery capacity remaining out of max capacity " << capacity << " mAh, using " << fuelGuageAlgorithm << "\n";
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
    std::cout << model <<" battery replaced with type: " << newBattery.type << "\n";
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
    double attitude;
    double orbitalVelocity = 7.8;
    float antennaCenterFrequency = 2.4f;
    void switchImagingModality();
    int transmitDataToGroundStation();
    float monitorBatteryChargeLevel();
};

WeatherSatellite::WeatherSatellite() : attitude(45.7)
{
    std::cout << "WeatherSatellite being constructed\n";
}

void WeatherSatellite::switchImagingModality()
{
    std::cout << "satellite attitude is " <<  attitude << " degrees, switching imaging modality from visible to infrared\n";
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
    float maximumShutterSpeed;
    float weight = 1.2f;
    std::string brand = "Canon";
    void releaseShutter();
    void advanceFilm();
    void engageLightmeter();
};

FilmCamera::FilmCamera() : maximumShutterSpeed(0.001f)
{
    std::cout << "FilmCamera being constructed\n";
}

void FilmCamera::releaseShutter()
{
    std::cout << "shutter released at shutter speed: " << maximumShutterSpeed << " s\n";
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
    float motionSensorSensitivity;
    float alarmLoudness = 110.0f;
    int backupBatteryCapacity = 10000;
    std::string connectivityType;
    bool detectIntrusion();
    int recordVideo();
    void sendAlertToSmartphone();
};

SecuritySystem::SecuritySystem() : motionSensorSensitivity(5.6f), connectivityType("WiFi")
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
    int motionDetectionSensitivity;
    void adjustBrightness(int level);
    void adjustLightColour(const std::string& colour);
    bool detectMotion();
};

LightingControl::LightingControl() : motionDetectionSensitivity(8)
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
    std::string filterQuality;
    std::string energyEfficiencyRating;
    int coolingCapacity = 5000;
    int heatingCapacity = 5000;
    void increaseRoomTemperature(float degrees);
    void filterIndoorAir();
    void optimiseEnergyUse();
};

HVACSystem::HVACSystem() : filterQuality("HEPA"), energyEfficiencyRating("A++")
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
    std::string supportedVideoFormat;
    int maximumAudioOutputLevel = 120;
    std::string brand = "Sony";
    void playVideoContent();
    float streamAudioContent();
    bool connectToBluetoothDevice();
};

EntertainmentSystem::EntertainmentSystem() : supportedVideoFormat("4K UHD")
{
    std::cout << "EntertainmentSystem being constructed\n";
}

void EntertainmentSystem::playVideoContent()
{
    std::cout << "playing " << supportedVideoFormat << " video\n";
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
    std::string washCycleType;
    float energyConsumptionPerCycle = 0.5f;
    float waterUsagePerCycle = 10.0f;
    std::string model = "WashMaster 3000";
    std::string smartHomeCompatibility = "HomeKit";
    void washClothes();
    void optimisePowerUsageBasedOnLoad();
    bool sendAlertToHomeowners();
};

SmartAppliance::SmartAppliance() : washCycleType("cotton")
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

    Dog jackRussel;
    Dog::DogCollar pinkCollar;
    
    jackRussel.barkAtPostman();
    jackRussel.fetchBall();
    jackRussel.tryNewCollar(pinkCollar);
    jackRussel.currentCollar.attachLeash("gangster", true);
    jackRussel.currentCollar.adjustFit(15, 10.0f, 20.0f);
    jackRussel.currentCollar.remove(true);

    Laptop laptop;
    Laptop::Battery replacementBattery;

    laptop.replaceBattery(replacementBattery);
    laptop.launchProgram("Logic");
    laptop.invokeCompiler();
    laptop.currentBattery.charge(90.0f);
    laptop.currentBattery.checkCapacityRemaining("FastGauge");
    laptop.currentBattery.limitChargeCurrent(2.5f, 90.0f);

    WeatherSatellite sputnik;

    sputnik.switchImagingModality();
    sputnik.transmitDataToGroundStation();
    sputnik.monitorBatteryChargeLevel();

    FilmCamera canonA1;

    canonA1.releaseShutter();
    canonA1.advanceFilm();
    canonA1.engageLightmeter();

    SecuritySystem megaAlarm;

    megaAlarm.detectIntrusion();
    megaAlarm.recordVideo();
    megaAlarm.sendAlertToSmartphone();

    LightingControl megaLight;

    megaLight.adjustBrightness(42);
    megaLight.adjustLightColour("violet");
    megaLight.detectMotion();

    HVACSystem megaHVAC;

    megaHVAC.increaseRoomTemperature(11.3f);
    megaHVAC.filterIndoorAir();
    megaHVAC.optimiseEnergyUse();

    EntertainmentSystem boseWholeHome;

    boseWholeHome.playVideoContent();
    boseWholeHome.streamAudioContent();
    boseWholeHome.connectToBluetoothDevice();

    SmartAppliance whirlpool3000;

    whirlpool3000.washClothes();
    whirlpool3000.optimisePowerUsageBasedOnLoad();
    whirlpool3000.sendAlertToHomeowners();

    SmartHomeSystem gigaHome;

    gigaHome.monitorHomeTemperature();
    gigaHome.controlLighting("GAMES_ROOM");
    gigaHome.triggerAlarmSound();

    std::cout << "jack russel's weight: " << jackRussel.weight << " kg" << "\n";
    std::cout << "jack russel's collar material: " << jackRussel.currentCollar.material << "\n";
    std::cout << "laptop brand: " << laptop.brand << "\n";
    std::cout << "laptop's battery's charge capacity: " << laptop.currentBattery.capacity << " mAh\n";
    std::cout << "sputnik's orbital velocity is: " << sputnik.orbitalVelocity << " ms^-1\n";
    std::cout << "Canon A1's viewfinder type: " << canonA1.viewfinderType << " \n";
    std::cout << "mega alarm loudness: " << megaAlarm.alarmLoudness << " dB\n";
    std::cout << "mega light has " << megaLight.numberOfConnectedLights << " connected lights\n";
    std::cout << "mega HVAC has a " << megaHVAC.filterQuality << " filter\n";
    std::cout << "Bose entertainment system supports " << boseWholeHome.supportedVideoFormat << "\n";
    std::cout << "Whirlpool 300 uses " << whirlpool3000.waterUsagePerCycle << " litres of water per cycle\n";
    std::cout << "giga home system smart appliance compatibility type is " << gigaHome.smartAppliance.smartHomeCompatibility << '\n';

    std::cout << "good to go!" << std::endl;
}
