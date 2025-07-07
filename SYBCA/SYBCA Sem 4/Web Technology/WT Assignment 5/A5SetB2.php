<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetB2</title>
</head>
<body>
    <h2>Search Salary Details by Department</h2>

    <form method="POST">
        <label for="deptName">Select Department Name:</label>
        <select id="deptName" name="dept_name" required>
            <option value="">-- Select Department --</option>
            <?php
            $host = "localhost";
            $db = "tejasSE2203";
            $user = "postgres";
            $pass = "12345";
            
            $conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

            if (!$conn) {
                die("Database connection failed.");
            }

            $dept_query = "SELECT dname FROM Dept";
            $dept_result = pg_query($conn, $dept_query);

            if (!$dept_result) {
                echo "<p>Error fetching department names.</p>";
                exit;
            }

            while ($row = pg_fetch_assoc($dept_result)) {
                echo "<option value=\"" . htmlspecialchars($row['dname']) . "\">" . htmlspecialchars($row['dname']) . "</option>";
            }

            pg_close($conn);
            ?>
        </select>
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
            SELECT 
                MAX(e.esalary) AS max_salary,
                MIN(e.esalary) AS min_salary,
                SUM(e.esalary) AS total_salary
            FROM Emp e
            JOIN Dept d ON e.dno = d.dno
            WHERE d.dname = $1
        ";

        $result = pg_query_params($conn, $query, [$dept_name]);

        if (!$result) {
            echo "<p>Error fetching data.</p>";
            exit;
        }

        $row = pg_fetch_assoc($result);

   
        if ($row['max_salary']) {
            echo "<h3>Department Name: <strong>$dept_name</strong></h3>";
            echo "<table border='1' cellpadding='10' cellspacing='0'>";
            echo "<tr>
                    <th>Maximum Salary</th>
                    <th>Minimum Salary</th>
                    <th>Sum of the Salary</th>
                  </tr>";
            echo "<tr>
                    <td>" . htmlspecialchars($row['max_salary']) . "</td>
                    <td>" . htmlspecialchars($row['min_salary']) . "</td>
                    <td>" . htmlspecialchars($row['total_salary']) . "</td>
                  </tr>";
            echo "</table>";
        } else {
            echo "<p>No employees found in the <strong>$dept_name</strong> department.</p>";
        }

        pg_close($conn);
    }
    ?>
</body>
</html>
