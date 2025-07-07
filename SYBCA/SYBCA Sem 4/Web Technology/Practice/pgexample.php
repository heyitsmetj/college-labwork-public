<?php
    $db = pg_connect("host = localhost port = 5432 dbname = postgres user = postgres password = mit@2022");
    echo "Connection is successfully done!";


    $sql = "CREATE TABLE son(FirstName varchar(15), LastName varchar(15), Age int);";
    pg_query($db, $sql);

    echo "Table is created!";

    pg_close($db);
?>