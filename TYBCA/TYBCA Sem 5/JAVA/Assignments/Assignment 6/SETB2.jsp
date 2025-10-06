<%@ page import="java.util.*, java.text.*" %>
<html>
<head>
    <title>Greeting Page</title>
</head>
<body>
    <form method="post">
        Enter your name: 
        <input type="text" name="username">
        <input type="submit" value="Greet Me">
    </form>
    <hr>

    <%
        String name = request.getParameter("username");

        if (name != null && !name.trim().isEmpty()) {
            // Get current time
            Calendar cal = new GregorianCalendar();
            int hour = cal.get(Calendar.HOUR_OF_DAY);

            // Format date and time
            Date now = cal.getTime();
            String date = new SimpleDateFormat("dd/MM/yyyy").format(now);
            String time = new SimpleDateFormat("HH:mm:ss").format(now);

            String greeting = "";
            String color = "";

            if (hour >= 5 && hour < 12) {
                greeting = "Good Morning " + name;
                color = "red";
            } else if (hour >= 12 && hour < 17) {
                greeting = "Good Afternoon " + name;
                color = "green";
            } else {
                greeting = "Good Evening " + name;
                color = "blue";
            }
    %>
            <h3 style="color:<%=color%>;"><%= greeting %></h3>
            Today's date: <%= date %><br>
            Current time: <%= time %>
    <%
        }
    %>
</body>
</html>
