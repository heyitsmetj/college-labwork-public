<?php
class Car
{
    public $make;
    public $model;
    private $year;

    public function __construct($make, $model, $year)
    {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    public function getCarDetails()
    {
        return "Make: {$this->make}, Model: {$this->model}, Year: {$this->year}";
    }

    private function calculateCarAge()
    {
        return date('Y') - $this->year;
    }

    public function getYear()
    {
        return $this->year;
    }
}

$car = new Car("Toyota", "Corolla", 2015);

echo "Class Name: " . get_class($car) . "<br>";

echo "<br>Properties of the Car class: <br>";
print_r(get_object_vars($car));

echo "<br>";

echo "<br>Methods of the Car class: <br>";
print_r(get_class_methods($car)); 

echo "<br>";

echo "<br>Does method 'getCarDetails' exist? " . (method_exists($car, 'getCarDetails') ? "Yes" : "No") . "<br>";
echo "Does method 'calculateCarAge' exist? " . (method_exists($car, 'calculateCarAge') ? "Yes" : "No") . "<br>";

echo "<br>";

echo "Does property 'make' exist? " . (property_exists($car, 'make') ? "Yes" : "No") . "<br>";
echo "Does property 'model' exist? " . (property_exists($car, 'model') ? "Yes" : "No") . "<br>";
echo "Does property 'year' exist? " . (property_exists($car, 'year') ? "Yes" : "No") . "<br>";
?>