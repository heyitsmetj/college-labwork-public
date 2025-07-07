<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetB3</title>
</head>
<body>
    <h2>Update Doctor's City to Mumbai</h2>

    <form method="POST">
        <label for="experience">Enter Experience (Years):</label>
        <input type="number" id="experience" name="experience" required>
        <input type="submit" value="Update">
    </form>

    <?php

    $host = "localhost";
    $db = "tejasSE2203";
    $user = "postgres";
    $pass = "12345";

    $conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

    if (!$conn) {
        die("Database connection failed.");
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $experience = intval($_POST['experience']);

        $update_query = "
            UPDATE Doctor
            SET city = 'Mumbai'
            WHERE experience < $1
        ";

        $result = pg_query_params($conn, $update_query, [$experience]);

        if (!$result) {
            echo "<p>Error updating records.</p>";
        } else {
            $affected_rows = pg_affected_rows($result);
            echo "<p><strong>$affected_rows</strong> doctor(s) updated successfully to Mumbai.</p>";
        }
    }

    $fetch_query = "SELECT doc_no, doc_name , experience, city FROM Doctor";
    $fetch_result = pg_query($conn, $fetch_query);

    if (!$fetch_result) {
        echo "<p>Error fetching doctor records.</p>";
    } else {

        echo "<h3>Doctor Table:</h3>";
        echo "<table border='1' cellpadding='10' cellspacing='0'>";
        echo "<tr><th>ID</th><th>Name</th><th>Experience (Years)</th><th>City</th></tr>";

        while ($row = pg_fetch_assoc($fetch_result)) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row['doc_no']) . "</td>";
            echo "<td>" . htmlspecialchars($row['doc_name']) . "</td>";
            echo "<td>" . htmlspecialchars($row['experience']) . "</td>";
            echo "<td>" . htmlspecialchars($row['city']) . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    }

    pg_close($conn);
    ?>
</body>
</html>
