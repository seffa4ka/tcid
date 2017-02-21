<?php

/**
 * @file
 * Common file.
 */

/**
 * Finds ID. Forming operation. Describes batch.
 */
function exchange_rates_initial_update_rate() {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'exchange_rates_entity');
  $res = $query->execute();

  if (isset($res['exchange_rates_entity'])) {
    $ids = array_keys($res['exchange_rates_entity']);
    $allEntities = array();
    $allCodesArray = array();

    foreach ($ids as $id) {
      $wrapper = entity_metadata_wrapper('exchange_rates_entity', $id);
      $allEntities[$wrapper->id->value()] = array($wrapper->code->value(), $wrapper->timestamp->value());
      array_push($allCodesArray, $wrapper->code->value());
    }

    $codesArray = array_keys(array_count_values($allCodesArray));
  }

  foreach ($codesArray as $code) {
    $maxDate[$code] = 0;
    $maxDateId[$code] = 0;
    foreach ($allEntities as $ekey => $entity) {
      if ($entity[0] === $code) {
        if ($entity[1] > $maxDate[$code]) {
          $maxDate[$code] = $entity[1];
          $maxDateId[$code] = $ekey;
        }
      }
    }
  }

  foreach ($maxDateId as $id) {
    $operations[] = array('exchange_rates_update_rate', array($id));
  }

  return array(
    'operations' => $operations,
    'finished' => 'exchange_rates_batch_finished',
    'title' => 'Update Exchange Rates',
    'init_message' => 'Initialized.',
    'progress_message' => 'Updated @current of @total.',
    'error_message' => 'Error.',
  );
}
