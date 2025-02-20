<?php
<<<<<<< HEAD
abstract class Shape
{
    abstract public function calculateArea();
}

class Triangle extends Shape
{
    private $base;
    private $height;

    public function __construct($base, $height)
    {
=======
class Shape {
    public function calculateArea() {
        return 0;
    }
}

class Triangle extends Shape {
    private $base;
    private $height;

    public function __construct($base, $height) {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        $this->base = $base;
        $this->height = $height;
    }

<<<<<<< HEAD
    public function calculateArea()
    {
=======
    public function calculateArea() {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        return 0.5 * $this->base * $this->height;
    }
}

<<<<<<< HEAD
class Square extends Shape
{
    private $side;

    public function __construct($side)
    {
        $this->side = $side;
    }

    public function calculateArea()
    {
=======
class Square extends Shape {
    private $side;

    public function __construct($side) {
        $this->side = $side;
    }

    public function calculateArea() {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        return $this->side * $this->side;
    }
}

<<<<<<< HEAD
class Rectangle extends Shape
{
    private $length;
    private $width;

    public function __construct($length, $width)
    {
=======
class Rectangle extends Shape {
    private $length;
    private $width;

    public function __construct($length, $width) {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        $this->length = $length;
        $this->width = $width;
    }

<<<<<<< HEAD
    public function calculateArea()
    {
=======
    public function calculateArea() {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        return $this->length * $this->width;
    }
}

<<<<<<< HEAD
class Circle extends Shape
{
    private $radius;

    public function __construct($radius)
    {
        $this->radius = $radius;
    }

    public function calculateArea()
    {
=======
class Circle extends Shape {
    private $radius;

    public function __construct($radius) {
        $this->radius = $radius;
    }

    public function calculateArea() {
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
        return pi() * $this->radius * $this->radius;
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $shapeType = $_POST['shape'];
    $area = 0;

    switch ($shapeType) {
        case 'triangle':
            $base = $_POST['base'];
            $height = $_POST['height'];
            $triangle = new Triangle($base, $height);
            $area = $triangle->calculateArea();
            break;
        case 'square':
            $side = $_POST['side'];
            $square = new Square($side);
            $area = $square->calculateArea();
            break;
        case 'rectangle':
            $length = $_POST['length'];
            $width = $_POST['width'];
            $rectangle = new Rectangle($length, $width);
            $area = $rectangle->calculateArea();
            break;
        case 'circle':
            $radius = $_POST['radius'];
            $circle = new Circle($radius);
            $area = $circle->calculateArea();
            break;
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<<<<<<< HEAD

<head>

    <title>A4SetA2</title>
</head>

=======
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Shape Area Calculator</title>
</head>
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
<body>
    <h1>Select a Shape to Calculate Area</h1>
    <form method="post">
        <input type="radio" name="shape" value="triangle" onclick="showInputs('triangle')"> Triangle<br>
        <input type="radio" name="shape" value="square" onclick="showInputs('square')"> Square<br>
        <input type="radio" name="shape" value="rectangle" onclick="showInputs('rectangle')"> Rectangle<br>
        <input type="radio" name="shape" value="circle" onclick="showInputs('circle')"> Circle<br><br>

        <div id="inputs"></div>

        <input type="submit" value="Calculate Area">
    </form>

    <?php if (isset($area)): ?>
        <h2>Area: <?php echo $area; ?></h2>
    <?php endif; ?>

    <script>
<<<<<<< HEAD
        function showInputs(shape) 
        {
            const inputsDiv = document.getElementById('inputs');
            inputsDiv.innerHTML = '';
=======
        function showInputs(shape) {
            const inputsDiv = document.getElementById('inputs');
            inputdiv.innerHTML = '';
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea

            if (shape === 'triangle') 
            {
                inputsDiv.innerHTML = 'Base: <input type="number" name="base" required><br>Height: <input type="number" name="height" required><br>';
            } 
            else if (shape === 'square') 
            {
                inputsDiv.innerHTML = 'Side: <input type="number" name="side" required><br>';
            } 
            else if (shape === 'rectangle') 
            {
                inputsDiv.innerHTML = 'Length: <input type="number" name="length" required><br>Width: <input type="number" name="width" required><br>';
            } 
            else if (shape === 'circle') 
            {
                inputsDiv.innerHTML = 'Radius: <input type="number" name="radius" required><br>';
            }
        }
    </script>
</body>
<<<<<<< HEAD

</html>
=======
</html>
>>>>>>> 426c3d3d36ad0243851ad9563200c0f1b8039fea
