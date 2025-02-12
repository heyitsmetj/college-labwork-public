<?php
interface Shape {
    public function area();
    public function volume();
}

class Cylinder implements Shape {
    private $radius;
    private $height;
    
    public const PI = 3.14159;

    public function __construct($r, $h) {
        $this->radius = $r;
        $this->height = $h;
    }
    
    public function display(){
        echo "Radius: " . $this->radius . "\n";
        echo "Height: " . $this->height . "\n";
    }

    public function area() {
        $area = 2 * self::PI * $this->radius * $this->height + 2 * self::PI * ($this->radius * $this->radius);
        echo "Surface Area of Cylinder: " . $area . "\n";
    }

    public function volume() {
        $volume = self::PI * ($this->radius * $this->radius) * $this->height;
        echo "Volume of Cylinder: " . $volume . "\n";
    }
}

$cylinder = new Cylinder(5, 4);
$cylinder->display();
$cylinder->area();
$cylinder->volume();
?>
