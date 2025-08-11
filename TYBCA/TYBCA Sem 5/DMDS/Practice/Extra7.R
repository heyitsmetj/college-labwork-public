year <- c(2001, 2002, 2003)
export <- c(26, 32, 35)
import <- c(35, 40, 50)

data <- rbind(export, import)

barplot(data, beside = TRUE, names.arg = year,
        col = c("blue", "green"),
        legend.text = c("Export", "Import"),
        main = "Export and Import Data",
        ylab = "Values")

