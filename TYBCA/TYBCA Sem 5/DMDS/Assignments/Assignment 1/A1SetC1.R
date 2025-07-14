data("airquality")
print(airquality)

input = airquality

plot(x = input$Wind, y = input$Temp,
     xlab = "Wind Speed",
     ylab = "Temperature",
     main = "Wind Speed vs Temperature"
)

plot(x = input$Ozone, y = input$Wind,
     xlab = "Ozone",
     ylab = "Wind",
     main = "Wind and Ozone"
)

subset_data <- subset(airquality, Temp > 70)

barplot(subset_data$Ozone,
        main = "Ozone Levels on Hot Days (Temp > 70)",
        ylab = "Ozone",
        col = "lightblue"
)
