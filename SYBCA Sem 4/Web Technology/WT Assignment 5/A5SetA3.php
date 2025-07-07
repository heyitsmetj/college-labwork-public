<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetA3</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }
        table, th, td {
            border: 1px solid black;
        }
        th, td {
            padding: 8px;
            text-align: left;
        }
    </style>
</head>
<body>
    <h2>Search Employee Count by Department</h2>

    <form method="POST">
        <label for="deptName">Enter Department Name:</label>
        <input type="text" id="deptName" name="dept_name" required>
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

        $dept_name = $_POST['dept_name'];

        $query = "
            SELECT e.eno, e.ename, d.dname
            FROM Emp e
            JOIN Dept d ON e.dno = d.dno
            WHERE d.dname = $1
        ";

        $result = pg_query_params($conn, $query, [$dept_name]);

        if (!$result) {
            echo "<p>Error fetching data.</p>";
            exit;
        }

        $emp_count = pg_num_rows($result);
        
        if ($emp_count > 0) {
            echo "<p>Number of employees in <strong>$dept_name</strong>: <b>$emp_count</b></p>";

            echo "<table>";
            echo "<tr><th>Employee ID</th><th>Employee Name</th><th>Department</th></tr>";

            while ($row = pg_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars($row['eno']) . "</td>";
                echo "<td>" . htmlspecialchars($row['ename']) . "</td>";
                echo "<td>" . htmlspecialchars($row['dname']) . "</td>";
                echo "</tr>";
            }

            echo "</table>";
        } else {
            echo "<p>No employees found in the <strong>$dept_name</strong> department.</p>";
        }

        pg_close($conn);
    }
    ?>
</body>
</html>
