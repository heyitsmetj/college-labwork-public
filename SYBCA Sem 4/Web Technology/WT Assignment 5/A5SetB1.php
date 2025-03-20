<!DOCTYPE html>
<html lang="en">
<head>
    <title>A5SetB1</title>
</head>
<body>
    <h2>Search Employees by Project</h2>

    <form method="POST">
        <label for="projectName">Select Project Name:</label>
        <select id="projectName" name="project_name" required>
            <option value="">-- Select Project --</option>
            <?php

            $host = "localhost";
            $db = "tejasSE2203";
            $user = "postgres";
            $pass = "12345";
            
            $conn = pg_connect("host=$host dbname=$db user=$user password=$pass");

            if (!$conn) {
                die("Database connection failed.");
            }

            $project_query = "SELECT pname FROM Project";
            $project_result = pg_query($conn, $project_query);

            if (!$project_result) {
                echo "<p>Error fetching project names.</p>";
                exit;
            }

            while ($row = pg_fetch_assoc($project_result)) {
                echo "<option value=\"" . htmlspecialchars($row['pname']) . "\">" . htmlspecialchars($row['pname']) . "</option>";
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

        $project_name = $_POST['project_name'];

        $query = "
            SELECT e.ename, e.edesignation, w.no_of_hrs_worked 
            FROM Emp e
            JOIN Works_on w ON e.eno = w.eno
            JOIN Project p ON w.pno = p.pno
            WHERE p.pname = $1
        ";

        $result = pg_query_params($conn, $query, [$project_name]);

        if (!$result) {
            echo "<p>Error fetching data.</p>";
            exit;
        }

        if (pg_num_rows($result) > 0) {
            echo "<h3>Employees working on project: $project_name</h3>";
            echo "<table border='1' cellpadding='10' cellspacing='0'>";
            echo "<tr><th>Employee Name</th><th>Designation</th><th>Hours Worked</th></tr>";
            while ($row = pg_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . htmlspecialchars($row['ename']) . "</td>";
                echo "<td>" . htmlspecialchars($row['edesignation']) . "</td>";
                echo "<td>" . htmlspecialchars($row['no_of_hrs_worked']) . "</td>";
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p>No employees found working on the <strong>$project_name</strong> project.</p>";
        }

        pg_close($conn);
    }
    ?>
</body>
</html>
