<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num1 = $_POST["num1"];
    $num2 = $_POST["num2"];
    $operation = $_POST['operation'];
    $result = 0;

    switch ($operation) {
        case 'add':
            $result = $num1 + $num2;
            $operation = '+';
            break;
        case 'subtract':
            $result = $num1 - $num2;
            $operation = '-';
            break;
        case 'multiply':
            $result = $num1 * $num2;
            $operation = '*';
            break;
        case 'divide':
            if ($num2 != 0) {
                $result = $num1 / $num2;
                $operation = '/';
            } else {
                $result = "Cannot divide by zero!";
            }
            break;
    }

    echo $num1 . $operation . $num2 . " = " . $result; 
}
?>