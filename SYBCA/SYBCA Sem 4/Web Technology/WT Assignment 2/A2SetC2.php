<!DOCTYPE html>
<html lang="en">
<head>
    <title>A2SetC2</title>
    <style>
        table {
            border-collapse: collapse;
            width: 80%;
            margin: 20px auto;
        }
        th, td {
            border: 1px solid #000;
            padding: 10px;
            text-align: center;
        }
    </style>
</head>
<body>
    <h1 style="text-align: center;">Item Details Form</h1>
    <form method="post" style="text-align: center;">
        <label for="itemCode">Item Codes (comma-separated):</label><br>
        <input type="text" id="itemCode" name="itemCode" required><br><br>

        <label for="itemName">Item Names (comma-separated):</label><br>
        <input type="text" id="itemName" name="itemName" required><br><br>

        <label for="unitsSold">Units Sold (comma-separated):</label><br>
        <input type="text" id="unitsSold" name="unitsSold" required><br><br>

        <label for="rate">Rates (comma-separated):</label><br>
        <input type="text" id="rate" name="rate" required><br><br>

        <button type="submit" name="submit">Generate Bill</button>
    </form>

<?php

    if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['submit'])) 
    {

        $itemCodes = explode(',', $_POST['itemCode']);
        $itemNames = explode(',', $_POST['itemName']);
        $unitsSold = explode(',', $_POST['unitsSold']);
        $rates = explode(',', $_POST['rate']);

        if (count($itemCodes) !== 5 || count($itemNames) !== 5 || count($unitsSold) !== 5 || count($rates) !== 5) {
            echo "<h2 style='color: red; text-align: center;'>Error: Please enter exactly 5 values for each field.</h2>";
            exit;
        }


        $unitsSold = array_map('intval', $unitsSold);
        $rates = array_map('floatval', $rates);

        echo "<h2 style='text-align: center;'>Generated Bill</h2>";
        echo "<table>";
        echo "<tr>
                <th>Item Code</th>
                <th>Item Name</th>
                <th>Units Sold</th>
                <th>Rate (per unit)</th>
                <th>Total Amount</th>
              </tr>";

        $grandTotal = 0;

        for ($i = 0; $i < 5; $i++) 
        {
            $total = $unitsSold[$i] * $rates[$i];
            $grandTotal += $total;

            echo "<tr>
                    <td>{$itemCodes[$i]}</td>
                    <td>{$itemNames[$i]}</td>
                    <td>{$unitsSold[$i]}</td>
                    <td>Rs.{$rates[$i]}</td>
                    <td>Rs.{$total}</td>
                  </tr>";
        }

        echo "<tr>
                <td colspan='4' style='font-weight: bold;'>Grand Total</td>
                <td style='font-weight: bold;'>Rs.{$grandTotal}</td>
              </tr>";
        echo "</table>";
    }
?>

</body>
</html>
