import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# Set up Chinese font support
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# Create detailed sample data
data = {
    '城市': ['北京', '上海', '广州', '深圳', '杭州', '成都', '武汉', '重庆', '南京', '苏州'],
    '人口(百万)': [21.54, 24.87, 15.31, 13.44, 10.36, 16.33, 11.21, 31.02, 8.51, 12.75],
    'GDP(万亿)': [3.61, 4.32, 2.82, 2.77, 1.81, 1.77, 1.56, 2.36, 1.48, 2.27],
    '人均GDP(万元)': [16.76, 17.38, 18.42, 20.59, 17.47, 10.84, 13.91, 7.61, 17.39, 17.80]
}

df = pd.DataFrame(data)

# Create figure with multiple subplots
fig = plt.figure(figsize=(18, 12))
fig.suptitle('中国主要城市经济数据可视化', fontsize=16)

# Grid layout for subplots
gs = fig.add_gridspec(2, 3)

# 1. Population bar chart
ax1 = fig.add_subplot(gs[0, 0])
df.plot.bar(x='城市', y='人口(百万)', ax=ax1, color='skyblue', edgecolor='black')
ax1.set_title('城市人口 (百万)', pad=20)
ax1.set_ylabel('人口数量')
ax1.grid(axis='y', linestyle='--', alpha=0.7)

# 2. GDP pie chart
ax2 = fig.add_subplot(gs[0, 1])
explode = [0.1 if x == df['GDP(万亿)'].max() else 0 for x in df['GDP(万亿)']]
df.plot.pie(y='GDP(万亿)', labels=df['城市'], autopct='%1.1f%%',
           startangle=90, explode=explode, shadow=True,
           ax=ax2, textprops={'fontsize': 10})
ax2.set_title('GDP分布', pad=20)
ax2.set_ylabel('')

# 3. Per capita GDP bar chart
ax3 = fig.add_subplot(gs[0, 2])
df.plot.bar(x='城市', y='人均GDP(万元)', ax=ax3, color='lightgreen', edgecolor='black')
ax3.set_title('人均GDP (万元)', pad=20)
ax3.set_ylabel('人均GDP')
ax3.grid(axis='y', linestyle='--', alpha=0.7)

# 4. Population vs GDP scatter plot
ax4 = fig.add_subplot(gs[1, :])
# Convert to numpy array, then to list of floats, and scale bubble sizes
bubble_sizes = (df['人均GDP(万元)'].to_numpy() * 100).tolist()

# Create scatter plot with improved styling
df.plot.scatter(x='人口(百万)', y='GDP(万亿)', s=bubble_sizes,
               c='人均GDP(万元)', cmap='viridis', ax=ax4,
               edgecolor='black', alpha=0.8, linewidths=0.5)
ax4.set_title('人口与GDP关系 (气泡大小表示人均GDP)', pad=20)
ax4.set_xlabel('人口 (百万)')
ax4.set_ylabel('GDP (万亿)')
ax4.grid(True, linestyle='--', alpha=0.7)

# Add colorbar for scatter plot
cbar = plt.colorbar(ax4.collections[0], ax=ax4)
cbar.set_label('人均GDP (万元)')

# Adjust layout and display
plt.tight_layout()
plt.subplots_adjust(top=0.92)
plt.show()
