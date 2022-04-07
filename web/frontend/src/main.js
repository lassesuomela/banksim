import Vue from 'vue'
import Vuetify from "vuetify";
import "vuetify/dist/vuetify.min.css";
import App from './App.vue'
import router from './router'
import vuetify from './plugins/vuetify'
import 'material-design-icons-iconfont/dist/material-design-icons.css'
import Sidebar from "./components/Sidebar.vue"
import cards from "./components/Cards.vue"
import Pie from "./components/Pie.vue"
import Acctable from "./components/Acctable.vue"
import Accadd from "./components/accadd.vue"
import VueApexCharts from 'vue-apexcharts'


Vue.use(Vuetify);
Vue.config.productionTip = false
Vue.component("app-sidebar", Sidebar);
Vue.component("app-cards", cards);
Vue.component("app-Pie", Pie);
Vue.component("app-Acctable", Acctable);
Vue.component("app-Accadd", Accadd);
Vue.use(VueApexCharts);
Vue.component('apexchart', VueApexCharts);


new Vue({
  router,
  vuetify,
  render: h => h(App)
}).$mount('#app')

