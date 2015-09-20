# capacity_modeling.R
#
# Building a linear model on a "noisy" sample
# to demonstrate that it's not a good idea
# to make predictions outside of the data interval.

# RS20092015

library(ggplot2)

# Suppose we had an application whose memory consumption
# scaled with a parameter called "cells." 
# The true population parameters are, of course, unknown.
true.mem.consumption <- function(cells){
  return(5 * cells + 3)
}

# Build data frame for population.
c <- seq(1000, 60000, by = 1000) 
data <- data.frame(cells = c, 
                   mem.consumption = sapply(c, true.mem.consumption))

# Let's use 10 data points to build a model.
rows <- sample(length(c), 10)

# Now let's say when collecting the sample data there were some
# inefficiencies in our collection methodology so we don't get 
# very accurate samples. 
# Simulated by added jitter.
# NB: Surely there must be a more efficient way of doing below in R.
model.data <- data[rows, ]
model.data$mem.consumption <- sapply(model.data$mem.consumption, jitter, factor = 15.0)

# Build a linear model.
# fit <- lm(mem.consumption ~ cells, data = model.data)

# Plot the data and add a linear smoother with confidence interval.
p <- ggplot(data = model.data, aes(x = cells, y = mem.consumption)) + geom_point(colour="blue") + 
  stat_smooth(method = "lm", fullrange = FALSE)

# Plot the (unknown) exact scaling behaviour. 
p <- p + geom_point(data = data, aes(x = cells, y = mem.consumption), colour="red")

plot(p)