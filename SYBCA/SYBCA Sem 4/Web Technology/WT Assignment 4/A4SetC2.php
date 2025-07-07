<?php

interface Property
{
    public function setProperty($property);
    public function getProperty();
}

interface Home
{
    public function setHasApartment($bool);
    public function getHasSociety();
}

class Bunglow implements Property, Home
{
    private $property;
    private $hasApartment;
    private $hasGarden;

    public function __construct($hasGarden)
    {
        $this->hasGarden = $hasGarden;
    }

    public function setProperty($property)
    {
        $this->property = $property;
    }

    public function getProperty()
    {
        return $this->property;
    }

    public function setHasApartment($bool)
    {
        $this->hasApartment = $bool;
    }

    public function getHasSociety()
    {
        return $this->hasApartment ? true : false;
    }

    public function getHasGarden()
    {
        return $this->hasGarden;
    }
}

$bunglow = new Bunglow(true);
$bunglow->setProperty("Luxury Bunglow with 3 rooms");
$bunglow->setHasApartment(true);

echo "Property: " . $bunglow->getProperty() . "<br>";
echo "Has Apartment: " . ($bunglow->getHasSociety() ? "Yes" : "No") . "<br>";
echo "Has Garden: " . ($bunglow->getHasGarden() ? "Yes" : "No") . "<br>";

?>
