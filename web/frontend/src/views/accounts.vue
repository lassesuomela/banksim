
<template>
  <div>
    <app-sidebar />
    <app-Acctable />
    <br />
    <v-card rounded="4" class="blue-grey darken-3 elevation-1">
      <v-toolbar rounded="4" color="cyan darken-1" dark>
        <v-toolbar-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3"
          >All</v-toolbar-title>
        <v-spacer></v-spacer>
      </v-toolbar>
      <br />
      <app-Pie />
      <br />
    </v-card>
  </div>
</template>

<script>
</script>

<style scoped>
.overlap-icon {
  position: absolute;
  top: -33px;
  text-align: center;
  padding-top: 12px;
}
</style>
