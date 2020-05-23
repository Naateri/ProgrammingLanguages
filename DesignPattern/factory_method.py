from abc import ABC, abstractmethod

class ChevyCar(ABC):

    brand = "Chevrolet"
    #also includes year and model

    def __str__(self):
        return "Car: " + self.year + " " + self.brand + " " + self.model

    def print_hp(self):
        print("Horsepower:", self.hp)

    @abstractmethod
    def muscle_or_pickup(self):
        #Is the car a muscle car or is it a pickup truck?
        pass

class CamaroCar(ChevyCar):
    #Chevrolet Camaro Constructor
    def __init__(self):
        self.model = "Camaro ZL1"
        self.year = "2019"
        self.hp = "650"

    def muscle_or_pickup(self):
        #Chevrolet Camaro is a muscle car
        return "Muscle Car"

class SilveradoCar(ChevyCar):
    #Chevorlet Silverado Constructor
    def __init__(self):
        self.model = "Silverado LD"
        self.year = "2019"
        self.hp = "355"

    def muscle_or_pickup(self):
        #Chevrolet Silverado is a pickup truck
        return "Pickup truck"

class Creator(ABC):

    def __init__(self):
        self.car = self.factory_method()

    @abstractmethod
    def factory_method(self):
        #Different factory method per each car
        pass

class CamaroCreator(Creator):
    #Chevrolet Camaro instance creator
    def factory_method(self):
        return CamaroCar()

class SilveradoCreator(Creator):
    #Chevrolet Silverado instance creator
    def factory_method(self):
        return SilveradoCar()


def main():

    for concrete_creator in (CamaroCreator(), SilveradoCreator()):
        #Creating a Chevrolet Camaro and a Chevrolet Silverado
        my_car = concrete_creator.car
        print(my_car)
        my_car.print_hp()
        print(my_car.muscle_or_pickup())
    
if __name__ == '__main__':
    main()
