<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetB3</title>
</head>

<body>
    <form action="result.php" method="post">
    <h2>Select an Arithmetic Operation</h2>
        <label for="firstNumber">Enter First Number:</label>
        <input type="number" id="firstNumber" name="num1" required><br><br>

        <label for="secondNumber">Enter Second Number:</label>
        <input type="number" id="secondNumber" name="num2" required><br><br>

        <label>Select Operation:</label><br>
        <input type="radio" id="addition" name="operation" value="add" checked>
        <label for="addition">Addition (+)</label><br>

        <input type="radio" id="subtraction" name="operation" value="subtract">
        <label for="subtraction">Subtraction (-)</label><br>

        <input type="radio" id="multiplication" name="operation" value="multiply">
        <label for="multiplication">Multiplication (×)</label><br>

        <input type="radio" id="division" name="operation" value="divide">
        <label for="division">Division (÷)</label><br><br>

        <input type="submit" value="Calculate">
    </form>
</body>

</html>