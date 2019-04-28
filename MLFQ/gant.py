import plotly.plotly as pl
import plotly.figure_factory as ff
import plotly.offline as offline
# offline.init_notebook_mode(connected=False)

df = [dict(Task="Job A", Start='0', Finish='3'),
      dict(Task="Job B", Start='4', Finish='5'),
      dict(Task="Job C", Start='6', Finish='7')]
print(df)

fig = ff.create_gantt(df)
offline.plot(fig, filename="45")