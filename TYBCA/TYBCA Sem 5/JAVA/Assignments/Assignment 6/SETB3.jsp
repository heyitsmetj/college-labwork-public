<%@ page import="javax.servlet.http.*" %>
<html>
<head>
    <title>Visit Counter</title>
</head>
<body>
    <h2>Page Visit Counter (Using Cookies)</h2>

    <%
        int visitCount = 0;
        String visitMessage = "";

        // Get cookies from request
        Cookie[] cookies = request.getCookies();

        if (cookies != null) {
            for (Cookie c : cookies) {
                if (c.getName().equals("visitCount")) {
                    visitCount = Integer.parseInt(c.getValue());
                }
            }
        }

        // Increase visit count
        visitCount++;

        // Save updated count in cookie
        Cookie visitCookie = new Cookie("visitCount", String.valueOf(visitCount));
        visitCookie.setMaxAge(60*60*24*365); // 1 year
        response.addCookie(visitCookie);

        // Prepare message
        if (visitCount == 1) {
            visitMessage = "Welcome! This is your first visit.";
        } else {
            visitMessage = "You have visited this page " + visitCount + " times.";
        }
    %>

    <h3><%= visitMessage %></h3>
</body>
</html>
