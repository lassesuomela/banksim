<template>
  <v-navigation-drawer class="cyan darken-1" v-model="drawer" app>
    <v-list rounded dense>
        <v-list-item class="item" v-for="link in links" :key="link.text" router :to="link.route">
          
          <v-list-item-action>
            <v-icon class="#202227--text">{{ link.icon }}</v-icon>
          </v-list-item-action>
          <v-list-item-content>
            <v-list-item-title class="#202227--text">{{ link.text }}</v-list-item-title>
          </v-list-item-content>
        </v-list-item>
    </v-list>
  </v-navigation-drawer>
</template>



<script>
export default {
  name: "Sidebar",
  props: ["drawer"],
  data() {
    return {
      links: [
        { icon: 'mdi-account', text: 'Home', route: '/home' },
        { icon: 'mdi-cash', text: 'Register', route: '/register' },
        { icon: 'person', text: 'Login', route: '/' },
        { icon: 'mdi-door', text: 'Logout', route: '/logout' }
      ],
    };
  },
};
</script>


<style scoped>
  .item {
    margin: 5px;
    border-radius: 4px;
  }
  .item:hover {
    background: #0097A7;
  }
  .item:active {
    background: #00838F;
  }
</style>



