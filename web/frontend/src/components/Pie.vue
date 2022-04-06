<template>
  <div>
    <apexchart
      width="500"
      type="pie"
      :options="chartOptions"
      :series="series"
    ></apexchart>
  </div>
</template>

<script>
import axios from "../axios";
export default {
  data() {
    return {
      series: [],
      chartOptions: {
        chart: {
          width: "100%",
          type: "pie",
          background: "#37474F",
        },
        labels: [],
        theme: {
          palette: "palette10",
          mode: "dark",
          monochrome: {
            enabled: false,
          },
        },
        title: {
          text: "All",
        },
        dataLabels: {
          formatter(val, opts) {
            const name = opts.w.globals.labels[opts.seriesIndex];
            return [name, opts.w.config.series[opts.seriesIndex] + "€"];
          },
        },
      },
    };
  },
  beforeMount() {
    this.getAccounts();
  },
  methods: {
    getAccounts() {
      axios.get("/api/account").then((response) => {
        for (let i = 0; i < response.data.length; i++) {
          this.chartOptions.labels.push(response.data[i].name);
          this.series.push(Number(response.data[i].balance));
        }
      });
    },
  },
};
</script>