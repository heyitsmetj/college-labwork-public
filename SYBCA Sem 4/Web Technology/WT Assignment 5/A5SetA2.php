<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetA2</title>
</head>
<body>
    <h2>Search Sales Orders by Date</h2>

    <form method="POST">
        <label for="orderDate">Enter Date (YYYY-MM-DD):</label>
        <input type="date" id="orderDate" name="order_date" required>
        <input type="submit" value="Search">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {

        $host = "localhost";
        $db = "tejasSE2203";
        $user = "postgres";
        $pass = "12345";

        $conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

        if (!$conn) {
            die("Database connection failed.");
        }

        $order_date = $_POST['order_date'];

        $query = "
            SELECT so.sonumber, so.s_order_date, c.name, c.address
            FROM Sales_order so
            JOIN Client c ON so.clientno = c.clientno
            WHERE so.s_order_date < $1
        ";

        $result = pg_query_params($conn, $query, [$order_date]);

        if (!$result) {
            echo "<p>Error fetching data.</p>";
            exit;
        }

        if (pg_num_rows($result) > 0) {
            echo "<h3>Orders before: $order_date</h3>";
            echo "<table border='1' cellpadding='10' cellspacing='0'>";
            echo "<tr><th>Order No</th><th>Order Date</th><th>Client Name</th><th>Address</th></tr>";
            while ($row = pg_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>{$row['sonumber']}</td>";
                echo "<td>{$row['s_order_date']}</td>";
                echo "<td>{$row['name']}</td>";
                echo "<td>{$row['address']}</td>";
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>No orders found before this date.</p>";
        }

        pg_close($conn);
    }
    ?>
</body>
</html>
