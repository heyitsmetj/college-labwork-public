<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetA1</title>
</head>
<body>
    <h2>Search Properties by Owner</h2>

    <form method="POST">
        <label for="ownerInput">Enter Owner's Name:</label>
        <input type="text" id="ownerInput" name="owner_name" required>
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

        $owner_name = $_POST['owner_name'];

        $query = "SELECT pno, description, area FROM Property WHERE oname = $1";
        $result = pg_query_params($conn, $query, [$owner_name]);

        if (!$result) {
            echo "<p>Error fetching data.</p>";
            exit;
        }

        if (pg_num_rows($result) > 0) {
            echo "<h3>Properties owned by: $owner_name</h3>";
            echo "<table border='1' cellpadding='10' cellspacing='0'>";
            echo "<tr><th>Property No</th><th>Description</th><th>Area (sq ft)</th></tr>";
            while ($row = pg_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>{$row['pno']}</td>";
                echo "<td>{$row['description']}</td>";
                echo "<td>{$row['area']}</td>";
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>No properties found for this owner.</p>";
        }

        pg_close($conn);
    }
    ?>
</body>
</html>
