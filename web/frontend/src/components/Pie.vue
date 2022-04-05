<template>
        <div>
        <apexchart width="500" type="pie" :options="chartOptions" :series="series"></apexchart>
        </div>       
</template>

<script>
export default {
    data: function() {
      return {
          series: [5000, 3433, 3433,],
          chartOptions: {
            chart: {
              width: '100%',
              type: 'pie',
              background: '#202227'
            },
            labels: ["acc 1", "acc 2", "acc 3", ],
            theme: {
              palette: 'palette10',
              mode: 'dark',
              monochrome: {
                enabled: false
              }
            },
            title: {
              text: "All"
            },
            dataLabels: {
              formatter(val, opts) {
                const name = opts.w.globals.labels[opts.seriesIndex]
                return [name, opts.w.config.series[opts.seriesIndex] + '€']
              }
      },
    }
   }
 }
};
</script>