import pandas as pd;
import plotly.express as px
import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
medical_df=pd.read_csv('expenses.csv')


#print(medical_df)
#print(medical_df.info())
#print(medical_df.describe())

sns.set_style('darkgrid')
matplotlib.rcParams['font.size']=14
matplotlib.rcParams['figure.figsize']=(10,6)
matplotlib.rcParams['figure.facecolor']='#00000000'

non_smoker_df=medical_df[medical_df.smoker == 'no']

#print(medical_df.age.describe())

#fig=px.histogram(medical_df,x='age',marginal='box',nbins=47,title='DistributionOf Age')
#fig=px.histogram(medical_df,x='charges',marginal='box',color='smoker',color_discrete_sequence=['green','grey'],title='Annual Medical Charges')
#fig.update_layout(bargap=0.1)

#fig=px.scatter(medical_df,x='age',y='charges',color='smoker',opacity=0.8,hover_data=['sex'],title='Age vs. Charges')
#fig.update_traces(marker_size=5)
#fig.show()

# plt.title('Age vs Charges')
# sns.scatterplot(data=non_smoker_df,x='age',y='charges',alpha=0.7,s=15);

from sklearn.linear_model import LinearRegression

model=LinearRegression()
# help(model.fit)

inputs=non_smoker_df[['age']]
targets=non_smoker_df.charges
print('inputs.shape :',inputs.shape)
print('inputs.shape :',targets.shape)

model.fit(inputs, targets)
model.predict(np.array([[23],[37],[61]]))

predictions=model.predict(inputs)
print(predictions)

